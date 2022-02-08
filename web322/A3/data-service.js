const fs = require('fs');

var employees = [];
var departments = [];

module.exports.initialize = function(){
    return new Promise((resolve,reject)=>{
        fs.readFile("./data/employees.json", (err,data)=>{
            if(err){
                reject(err);
            }
            employees = JSON.parse(data);
            resolve();
        })
        fs.readFile("./data/departments.json", (err,data)=>{
            if(err){
                reject(err);
            }
            departments = JSON.parse(data);
            resolve();
        });
    });
};
let num = 0;
function toNegativeNumber(input){
    return new Promise((resolve,reject)=>{
        if(isNaN(input)){
            reject("input is not a number");
        }
        else if(input >= 0){
            reject("input is a positive number")
        }
        else{
            num = input * (-1);
        }
    })
}
/*
function toNegativeNumber(x) {
   if(isNaN(x)) { throw new Error("not a number!") };
   if(Number(x) >= 0) { throw new Error("0 or a negative number!") };
   return Number(x);
}

let num = NaN, input = document.getElementById("#input").value;


*/

module.exports.getAllEmployees = function(){
    return new Promise((resolve,reject)=>{
    if(employees.length == 0){
        reject("Data is corrupted");
    }
    else{
        resolve(employees);
    }
});
};

module.exports.getManagers = function(){
    return new Promise((resolve,reject)=>{
        var managers = {};
        var count = 0;
        for(var i = 0 ; i < employees.length; i++) {
             var managerCheck = employees[i];
            if(managerCheck.isManager == true){
            managers[count] = managerCheck;
            count++;
            }
        }
        if(managers.length == 0){
            reject("Data is corrupted");
        }
        else{
            resolve(managers);
        }
    });
};
module.exports.getDepartments = function (){
    return new Promise((resolve,reject)=>{
        if(departments.length == 0){
            reject("Data is corrupted");
        }
        else{
            resolve(departments);
        }
    });
};

module.exports.addEmployee = function (newEmp) {
    return new Promise(function (resolve, reject) {

        newEmp.isManager = (newEmp.isManager) ? true : false;
        newEmp.employeeNum = employees.length + 1;
        employees.push(newEmp);

        resolve();
    });

};

module.exports.getEmployeesByStatus = function (status) {
    return new Promise(function (resolve, reject) {

        var filteredEmployeees = [];

        for (let i = 0; i < employees.length; i++) {
            if (employees[i].status == status) {
                filteredEmployeees.push(employees[i]);
            }
        }

        if (filteredEmployeees.length == 0) {
            reject("No employee found based on the status");
        }

        resolve(filteredEmployeees);
    });
};

module.exports.getEmployeesByDepartment = function (department) {
    return new Promise(function (resolve, reject) {
        var filteredEmployeees = [];

        for (let i = 0; i < employees.length; i++) {
            if (employees[i].department == department) {
                filteredEmployeees.push(employees[i]);
            }
        }

        if (filteredEmployeees.length == 0) {
            reject("No employee works in the given department");
        }

        resolve(filteredEmployeees);
    });
};

module.exports.getEmployeesByManager = function (manager) {
    return new Promise(function (resolve, reject) {
        var filteredEmployeees = [];

        for (let i = 0; i < employees.length; i++) {
            if (employees[i].employeeManagerNum == manager) {
                filteredEmployeees.push(employees[i]);
            }
        }

        if (filteredEmployeees.length == 0) {
            reject("No employee works for the given manager");
        }

        resolve(filteredEmployeees);
    });
};

module.exports.getEmployeeByNum = function (num) {
    return new Promise(function (resolve, reject) {
        var foundEmployee = null;

        for (let i = 0; i < employees.length; i++) {
            if (employees[i].employeeNum == num) {
                foundEmployee = employees[i];
            }
        }

        if (!foundEmployee) {
            reject("Employee ID not valid");
        }

        resolve(foundEmployee);
    });
};