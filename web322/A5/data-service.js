const Sequelize = require('sequelize');

//mine
var sequelize = new Sequelize('', '', '', {
    host: '',
    dialect: 'postgres',
    port: 5432,
    dialectOptions: {
        ssl: {
            require: true,
            rejectUnauthorized: false
          }
    }
});

// Employee table
var Employee = sequelize.define('Employee', {
    employeeNum: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    firstName: Sequelize.STRING,
    lastName: Sequelize.STRING,
    email: Sequelize.STRING,
    SSN: Sequelize.STRING,
    addressStreet: Sequelize.STRING,
    addressCity: Sequelize.STRING,
    addressState: Sequelize.STRING,
    addressPostal: Sequelize.STRING,
    martialStatus: Sequelize.STRING,
    isManager: Sequelize.BOOLEAN,
    employeeManagerNum: Sequelize.INTEGER,
    status: Sequelize.STRING,
    department: Sequelize.INTEGER,
    hireDate: Sequelize.STRING
});

// Department table
var Department = sequelize.define('Department', {
    departmentId: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    departmentName: Sequelize.STRING
});

// reads employee and departments data
module.exports.initialize = function(){
    return new Promise(function (resolve, reject) {
        sequelize.sync().then(() => {
            resolve();   
        }).catch((err)=>{   
            reject("Unable to sync the database");
        });       
    });
}

// return all employees
module.exports.getAllEmployees = function(){
    return new Promise(function(resolve, reject) {
        Employee.findAll().then(function(data){
            resolve(data);
        }).catch((err) => {
            reject("No results returned");
        });
    });
}

// return all employees with the same status
module.exports.getEmployeesByStatus = function(status){
    return new Promise(function (resolve, reject) {
        Employee.findAll({
            where: {
                status: status
            }
        }).then(function(data){
            resolve(data);
        }).catch((err) => {
            reject("No results returned");
        });
    });
}

// return all employees in this department
module.exports.getEmployeesByDepartment = function(department){
    return new Promise(function (resolve, reject) {
        Employee.findAll({
            where: {
                department: department
            }
        }).then(function(data){
            resolve(data);
        }).catch((err)=>{
            reject("No results returned");
        });
    });
}

// return all employees with this manager
module.exports.getEmployeesByManager = function(manager){
    return new Promise(function (resolve, reject) {
        Employee.findAll({
            where: {
                employeeManagerNum: manager
            }
        }).then(function(data){
            resolve(data);
        }).catch((err)=> {
            reject("No results returned");
        });
    });
}

// return the employee with this employee number
module.exports.getEmployeeByNum = function(num){
    return new Promise(function (resolve, reject) {
        Employee.findAll({
            where: {
                employeeNum: num
            }
        }).then(function(data){
            resolve(data[0].dataValues);
        }).catch((err)=> {
            reject("No results returned");
        });
    });
}

// add an employee
module.exports.addEmployee = function(employeeData){
    return new Promise(function (resolve, reject) {
        employeeData.isManager = (employeeData.isManager) ? true : false;
        for (const field in employeeData) {
            if (employeeData[field] == "") {
                employeeData[field] = null;
            } 
        }
        Employee.create(employeeData)
        .then(()=>{
            resolve();
        }).catch((err)=> {
            reject("Unable to create employee");
        });
    });
}

// update an employee
module.exports.updateEmployee = function(employeeData){
    return new Promise(function (resolve, reject) {
        employeeData.isManager = (employeeData.isManager) ? true : false;
        for (const field in employeeData) {
            if (employeeData[field] == "") {
                employeeData[field] = null;
            } 
        }

        Employee.update(
            employeeData
        ,{
            where: { employeeNum: employeeData.employeeNum }
        }).then(()=>{
            resolve();
        }).catch((err)=> {
            reject("Unable to update employee");
        });
    });
}

// deletes an employee
module.exports.deleteEmployeeByNum = function(empNum){
    return new Promise(function (resolve, reject) {  
        Employee.destroy({
            where: { employeeNum: empNum } 
        }).then(() => { 
            resolve();
        }).catch((err) => {
            reject("Unable to delete employee");
        });
    });
}

// return all departments
module.exports.getDepartments = function(){
    return new Promise(function (resolve, reject) {
        Department.findAll().then(function(data){
            var fixed=[];
            for(var i =0; i < data.length; i++){
                fixed.push(data[i].dataValues);
            }
            resolve(fixed);
        }).catch((err)=> {
            reject("No results returned");
        });
    });
}

// add a department
module.exports.addDepartment = function(departmentData){
    return new Promise(function (resolve, reject) {
        for (const field in departmentData) {
            if (departmentData[field] == "") {
                departmentData[field] = null;
            } 
        }

        Department.create(departmentData)
        .then(()=>{
            resolve();
        }).catch((err)=> {
            reject("Unable to create department");
        });
    });
}

// update a department
module.exports.updateDepartment = function(departmentData){
    return new Promise(function (resolve, reject) {
        for (const field in departmentData) {
            if (departmentData[field] == "") {
                departmentData[field] = null;
            } 
        }

        Department.update(
            departmentData
        ,{
            where: { departmentId: departmentData.departmentId }
        }).then(()=>{
            resolve();
        }).catch((err)=> {
            reject("Unable to update department");
        });
    });
}

// return the department with this department id
module.exports.getDepartmentById = function(id){
    return new Promise(function (resolve, reject) {
        Department.findAll({
            where: {
                departmentId: id
            }
        }).then(function(data){
            resolve(data[0].dataValues);
        }).catch((err)=> {
            reject("No results returned");
        });
    });
}
