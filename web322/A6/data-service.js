const dataServiceAuth = require('./data-service-auth');
const Sequelize = require('sequelize');
//Setting dabatase connection
var sequelize = new Sequelize('', '', '', {
        host: '',
        dialect: 'postgres',
        port: 5432,
        dialectOptions: {
                ssl: { required: true,
                        rejectUnauthorized: false}
        }
});

//creating tables
//Employee Table/model
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
        maritalStatus: Sequelize.STRING,
        isManager: Sequelize.BOOLEAN,
        employeeManagerNum: Sequelize.INTEGER,
        status: Sequelize.STRING,
        department: Sequelize.INTEGER,
        hireDate: Sequelize.STRING,
});
//Setting Department Model
var Department = sequelize.define('Department', {
        departmentId: {
                type: Sequelize.INTEGER,
                primaryKey: true,
                autoIncrement: true
        },
        departmentName: Sequelize.STRING
});

module.exports.initialize = function() {
        return new Promise((resolve, reject) => {
            sequelize.sync()
            .then(() => resolve())
            .catch((err) => reject(err));
        });
    };

module.exports.getAllEmployees = () => {
        return new Promise(function(resolve, reject){
                Employee.findAll({order: ['employeeNum']}).then((data) => {
                        data = data.map(value => value.dataValues);
                        resolve(data);
                }).catch((err) => {
                        reject("No results returned.");
                })
        })
}

module.exports.getManagers = () => {
        return new Promise (function(resolve, reject) {
               Employee.findAll({where: {
                        isManager: true
                } 
                }).then((data)=>{
                        resolve(data)
                }).catch((err)=> {
                        reject("No results returned.")
                })
        })
}

module.exports.getDepartments = () => {
        return new Promise (function(resolve, reject) {
                Department.findAll({order: ['departmentId']}).then((data)=>{
                        data = data.map(value => value.dataValues);
                        resolve(data);
                }).catch((err)=> {
                        reject("No results returned.")
                })
        })
}

module.exports.addEmployee = (employeeData) => {
        return new Promise (function(resolve, reject){
                employeeData.isManager = employeeData.isManager? true : false;
                for (let i in employeeData){
                        if(employeeData[i] == "")
                                employeeData[i] = null;
                }
                Employee.create(employeeData).then(()=>{resolve("Employee added!");})
                .catch((err) => reject("Unable to create employee"));
        })
}

module.exports.deleteEmployeeByNum = (empNum) => {
        return new Promise ((resolve, reject) => {
                Employee.destroy({where: {employeeNum: empNum}})
                .then(() => {
                        resolve("Employee deleted.");
                })
                .catch((err) => reject("Unable to delete this employee."))
        })        
}

module.exports.deleteDepartmentByNum = (depNum) => {
        return new Promise ((resolve, reject) => {
                Department.destroy({where: {departmentId: depNum}})
                .then(()=> {
                        resolve("Department deleted.");
                }).catch((err)=> {
                        reject("Unable to delete this department");
                })
        })
}

module.exports.addDepartment = (departmentData) => {
        return new Promise (function(resolve, reject){
                for (let i  in departmentData) {
                        if (departmentData[i] == ""){
                                departmentData[i] = null;
                        }
                }
                Department.create(departmentData)
                .then(() => {resolve()})
                .catch((err)=> {reject("Unable to create deparment.")})
        }); 
}

module.exports.updateDepartment = (departmentData) => {
        return new Promise (function(resolve, reject) {
                for (let i  in departmentData) {
                        if (departmentData[i] == ""){
                                departmentData[i] = null;
                        }
                } //
                Department.update(departmentData, {where: {
                        departmentId: departmentData.departmentId
                        }
                })
                .then(()=>{
                        resolve();
                })
                .catch((err)=>{reject("Unable to update department.")})
        })
}

module.exports.getDepartmentById = (id) => {
        return new Promise ((resolve, reject) =>{
                Department.findAll({where: {departmentId: id}})
                .then((data)=>{ 
                        data = data.map(value => value.dataValues);
                        resolve(data[0]);
                }).catch((err)=>reject("No results returned"))
        })
}


module.exports.getEmployeesByStatus = (status) => {
        return new Promise (function(resolve, reject) {
                Employee.findAll({where: {status: status}})
                .then((data) => {
                        data = data.map(value => value.dataValues);
                        resolve(data);
                }).catch((err) => {
                        reject("No results returned.");
                })
        })
}

module.exports.getEmployeesByDepartment = (department) => {
        return new Promise (function(resolve, reject) {
                Employee.findAll({where: {department: department}})
                .then((data)=> {
                        data = data.map(value => value.dataValues);
                        resolve(data);
                }).catch((err) => {
                        reject("No results returned.");
                })
        })          
}

module.exports.getEmployeesByManager = (manager) => {
        return new Promise((resolve, reject) => {
                Employee.findAll({where: {employeeManagerNum: manager}})
                .then((data)=>{
                        data = data.map(value => value.dataValues);
                        resolve(data);
                }).catch((err)=> {
                        reject("No results returned.");
                })
        })
}


module.exports.getEmployeeByNum = (num) => {
        return new Promise ((resolve, reject) => {
                Employee.findAll({where: {employeeNum: num}})
                .then((data)=>{
                        data = data.map(value => value.dataValues);
                        resolve(data[0]);
                }).catch((err)=>{
                        reject("No results returned.");
                })
        })
}

module.exports.updateEmployee = (employeeData) => {
        return new Promise ((resolve, reject) => {
                employeeData.isManager = employeeData.isManager? true : false;
                for (let i in employeeData){
                        if(employeeData[i] == "")
                                employeeData[i] = null;
                }
                Employee.update(employeeData, {where: {employeeNum: employeeData.employeeNum}})
                .then(()=>{resolve();})
                .catch((err)=>{reject("Unable to update employee");})
        })
}

