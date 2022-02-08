const Sequelize = require('sequelize');
var sequelize = new Sequelize('d7tjom5oje309u', 'xzmyqdvnbjemxr', '9256490e4beb84f975541410d7490e21618467805b5d72d017846139b6a1afea', {
    host: 'ec2-52-45-73-150.compute-1.amazonaws.com',
    dialect: 'postgres',
    port: 5432,
    dialectOptions: {
        ssl: { rejectUnauthorized: false }
    }
});

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
    hireDate: Sequelize.STRING
});
var Department = sequelize.define('Department', {
    departmentId: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    departmentName: Sequelize.STRING
});
Department.hasMany(Employee, {foreignKey: 'department'});


module.exports.initialize = function(){
    return new Promise(function (resolve, reject){
        sequelize.sync().then( () => {resolve()}).catch(() => {reject("unable to sync the database")});
        
});
};

module.exports.getAllEmployees = function(){
    return new Promise(function (resolve, reject) {
        Employee.findAll().then( (data) => {resolve(data)}).catch( () => {reject("no results returned")});
        
});

};

module.exports.getManagers = function(){
    return new Promise(function (resolve, reject) {
        reject();
});

};
module.exports.getDepartments = function (){
    return new Promise(function (resolve, reject) {
        Department.findAll().then((data) => {resolve(data)}).catch(() => {reject("no results returned")});
});

};

module.exports.getEmployeesByStatus = function (status) {
    return new Promise(function (resolve, reject) {
        Employee.findAll({ 
            where: {
                status: status
            }
        }).then((data) => {resolve(data)}).catch(() => {reject("no results returned")});
    
});

};

module.exports.getEmployeesByDepartment = function (department) {
    return new Promise(function (resolve, reject) {
        Employee.findAll({ 
            where: {
                department: department
            }
        }).then((data) => {resolve(data)}).catch(() => {reject("no results returned")});
});

};

module.exports.getEmployeesByManager = function (manager) {
    return new Promise(function (resolve, reject) {
        Employee.findAll({ 
            where: {
                employeeManagerNum: manager
            }
        }).then((data) => {resolve(data)}).catch(() => {reject("no results returned")});
});

};

module.exports.getEmployeeByNum = function (num) {
    return new Promise(function (resolve, reject) {
    Employee.findAll({ 
        where: {
            employeeNum: num
        }
    }).then((data) => {resolve(data[0])}).catch(() => {reject("no results returned")});
});

};

module.exports.addEmployee = function (newEmp) {
    return new Promise(function (resolve, reject) {
        newEmp.isManager = (newEmp.isManager) ? true : false;
        for (const prop in newEmp) {
            if(prop == ""){
                prop = null;
            }
        }
        Employee.create(newEmp).then(() => {resolve()}).catch(() => {reject("unable to create employee")});
        //const new_user = Employee.build(newEmp);
        //new_user.save().then(() => {resolve()}).catch(() => {reject("unable to create employee")});
    });


};

module.exports.updateEmployee = function (employeeData) {
    return new Promise(function (resolve, reject) {
        employeeData.isManager = (employeeData.isManager) ? true : false;
        for (const prop in employeeData) {
            if(prop == ""){
                prop = null;
            }
        }
        Employee.find({ where: { employeeNum: employeeData.employeeNum } })
        .on('success', function (Employee) {
            // Check if record exists in db
            if (Employee) {
                Employee.update(employeeData).success(() => {resolve()}).error(() => {reject("unable to update employee")});
            }
        })
});

};


module.exports.addDepartment = function (newDep) {
    return new Promise(function (resolve, reject) {
        for (const prop in newDep) {
            if(prop == ""){
                prop = null;
            }
        }
        Department.create(newDep).then(() => {resolve()}).catch(() => {reject("unable to create department")});
        //Department.create({
        //    departmentName : newDep.departmentName
        //}).then(() => {resolve()}).catch(() => {reject("unable to create department")});
        //Department.create({departmentName : newDep}).then(() => {resolve()}).catch(() => {reject("unable to create department")});
    });


};

module.exports.updateDepartment = function (departmentData) {
    return new Promise(function (resolve, reject) {
        for (const prop in departmentData) {
            if(prop == ""){
                prop = null;
            }
        }
        Department.find({ where: { departmentId: departmentData.departmentId } })
        .on('success', function (department) {
            // Check if record exists in db
            if (department) {
                department.update(departmentData).success(() => {resolve()}).error(() => {reject("unable to update department")});
            }
        })
});

};

module.exports.getDepartmentById = function (id) {
    return new Promise(function (resolve, reject) {
    Department.findAll({ 
        where: {
            departmentId: id
        }
    }).then(function (data) {resolve(data[0])}).catch(() => {reject("no results returned")});
});

};

module.exports.deleteDepartmentById = function (id) {
    return new Promise(function (resolve, reject) {
    /*getDepartmentById(id).then(function (data) {
        data.destroy().success(() => {resolve()}).error(() => {reject("unable to delete department")});
    });
    Department.destroy(this.getDepartmentById(id))
    .then(() => {resolve()}).catch(() => {reject("unable to delete department")});*/
    getDepartmentById(id).then(() => {resolve()}).catch(() => {reject("unable to delete department")});
});

};

module.exports.deleteEmployeeByNum = function (empNum) {
    return new Promise(function (resolve, reject) {
    getEmployeeByNum(empNum).then(function (data) {
        data.destroy().success(() => {resolve("destroyed")}).error(() => {reject("unable to delete employee")});
    });
});

};