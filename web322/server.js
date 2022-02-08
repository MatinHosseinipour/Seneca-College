/*********************************************************************************
*  WEB322 – Assignment 05
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part *  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
* 
*  Name: Matin Hosseini Pour Student ID: 151267192 Date: March 26th 2021
*  Online (Heroku) Link: https://hidden-anchorage-42358.herokuapp.com/
*
********************************************************************************/ 

var express = require("express");
var app = express();
var path = require("path");
const data_serv = require("./data-service");
const multer = require("multer");
const fs = require("fs");
const bodyParser = require('body-parser');
const exphbs = require('express-handlebars');
const { homedir } = require("os");
//const employees = require("./data/employees.json");
//const departments = require("./data/departments.json");

const storage = multer.diskStorage({
  destination: "./public/images/uploaded",
  filename: function (req, file, cb) {
    cb(null, Date.now() + path.extname(file.originalname));
  }
});
const upload = multer({ storage: storage });
var HTTP_PORT = process.env.PORT || 8080;

function onHttpStart() {
  console.log("Express http server listening on port " + HTTP_PORT);
}
app.use(express.static('public')); 
app.use(bodyParser.urlencoded({ extended: true }));
app.engine('.hbs', exphbs({ extname: '.hbs', defaultLayout: 'main',
helpers: {
      navLink: function(url, options){
          return '<li' + 
              ((url == app.locals.activeRoute) ? ' class="active" ' : '') + 
              '><a href="' + url + '">' + options.fn(this) + '</a></li>';
      },
      equal: function (lvalue, rvalue, options) {
        if (arguments.length < 3)
            throw new Error("Handlebars Helper equal needs 2 parameters");
        if (lvalue != rvalue) {
            return options.inverse(this);
        } else {
            return options.fn(this);
        }
      }

}
}));
app.set('view engine', '.hbs');


app.use(function(req,res,next){
  let route = req.baseUrl + req.path;
  app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
  next();
});


/*
app.get("/", function(req,res){
  res.sendFile(path.join(__dirname, "views/home.html"));
});
*/
app.get("/", function(req,res){
  res.render('home');
});

app.get("/about", function(req,res){
  //res.sendFile(path.join(__dirname, "views/about.html"));
  res.render('about');
});

/*
app.get("/employees", function(req,res){
    //res.json(JSON.stringify(employees));
    //res.json(employees);
    data_serv.getAllEmployees().then(function(data){
      res.json(data);
    });
});
*/

app.get("/employees", (req, res) => {
  if (req.query.status) {
      data_serv.getEmployeesByStatus(req.query.status).then((data) => {
          //res.json(data);
          if(data.length > 0){
            res.render("employees", {employees:data.map(value => value.dataValues)});
          }else{
            res.render("employees",{ message: "no results" });
          }
      }).catch((err) => {
          //res.json({ message: err });
          res.render("employees", {message: err});
      });
  } else if (req.query.department) {
     data_serv.getEmployeesByDepartment(req.query.department).then((data) => {
          //res.json(data);
          if(data.length > 0){
            res.render("employees", {employees:data.map(value => value.dataValues)});
          }else{
            res.render("employees",{ message: "no results" });
          }     
        }).catch((err) => {
          //res.json({ message: err });
          res.render("employees", {message: err});
      });
  } else if (req.query.manager) {
      data_serv.getEmployeesByManager(req.query.manager).then((data) => {
          //res.json(data);
          if(data.length > 0){
            res.render("employees", {employees:data.map(value => value.dataValues)});
          }else{
            res.render("employees",{ message: "no results" });
          }
          }).catch((err) => {
         // res.json({ message: err });
         res.render("employees", {message: err});
      });
  } else {
      data_serv.getAllEmployees().then((data) => {
          //res.json(data);
          if(data.length > 0){
            res.render("employees", {employees:data.map(value => value.dataValues)});
          }else{
            res.render("employees",{ message: "no results" });
          }
          }).catch((err) => {
          //res.json({ message: err });
          res.render("employees", {message: err});
      });
  }
});

/*app.get("/employee/:empNum", (req, res) => {
  data_serv.getEmployeeByNum(req.params.empNum).then((data) => {
      //res.json(data);
      res.render("employee", { employee: data }); 
  }).catch((err) => {
      //res.json({message: err });
      res.render("employee",{message: err}); 
  });
});*/

app.get("/employee/:empNum", (req, res) => {

  // initialize an empty object to store the values
  let viewData = {};

  data_serv.getEmployeeByNum(req.params.empNum).then((data) => {
      if (data) {
          viewData.employee = data; //store employee data in the "viewData" object as "employee"
      } else {
          viewData.employee = null; // set employee to null if none were returned
      }
  }).catch(() => {
      viewData.employee = null; // set employee to null if there was an error 
  }).then(data_serv.getDepartments)
  .then((data) => {
      viewData.departments = data; // store department data in the "viewData" object as "departments"

      // loop through viewData.departments and once we have found the departmentId that matches
      // the employee's "department" value, add a "selected" property to the matching 
      // viewData.departments object

      for (let i = 0; i < viewData.departments.length; i++) {
          if (viewData.departments[i].departmentId == viewData.employee.department) {
              viewData.departments[i].selected = true;
          }
      }

  }).catch(() => {
      viewData.departments = []; // set departments to empty if there was an error
  }).then(() => {
      if (viewData.employee == null) { // if no employee - return an error
          res.status(404).send("Employee Not Found");
      } else {
          res.render("employee", { viewData: viewData }); // render the "employee" view
      }
  });
});


app.get("/department/:departmentId", (req, res) => {
  data_serv.getDepartmentById(req.params.departmentId).then((data) => {
      //res.json(data);
      if(data.length > 0){
        res.render("department", { department: data.map(value => value.dataValues) }); 
      }
      else{
        res.status(404).send("Department Not Found"); 
      }
  }).catch((err) => {
      //res.json({message: err });
      res.status(404).send("Department Not Found"); 
  });
});

app.get("/department/delete/:departmentId", (req, res) => {
  data_serv.deleteDepartmentById(req.params.departmentId).then(() => {
      res.render('departments');

  }).catch((err) => {
      res.status(500).send("Unable to Remove Department / Department not found)");
     });
});

app.get("/employee/delete/:empNum", (req, res) => {
  data_serv.deleteEmployeeByNum(req.params.departmentId).then(() => {
      res.render('employees');

  }).catch((err) => {
      res.status(500).send("Unable to Remove Employee / Employee not found)");
     });
});

app.get("/managers", function(req,res){
    /*var managers = {};
    var count = 0;
    for(var i = 0 ; i < employees.length; i++) {
        var managerCheck = employees[i];
        if(managerCheck.isManager == true){
        managers[count] = managerCheck;
        count++;
        }
    }
    //res.json(managers);
    res.json(JSON.stringify(managers));*/
    data_serv.getManagers().then(function(data){
      res.json(data);
    });
});

app.get("/studentList/:option", function(req,res){
  res.json(
		
	);
});

app.get("/departments", function(req,res){
    //res.json(JSON.stringify(departments));
    //res.json(departments);
    data_serv.getDepartments().then(function(data){
      //res.json(data);
      if(data.length > 0){
        res.render("departments", {departments:data.map(value => value.dataValues)});
      }else{
        res.render("departments",{ message: "no results" });
      }
    }).catch((err) => {
      res.render('departments',{message: err });
  });
});

app.get("/images/add", (req,res) => {
 // res.sendFile(path.join(__dirname, "/views/addImage.html"));
res.render('addImage');
});

app.get("/employees/add", (req,res) => {
  //res.sendFile(path.join(__dirname, "/views/addEmployee.html"));
  data_serv.getDepartments().then(function (data){
    res.render("addEmployee", {departments: data.map(value => value.dataValues)});
  }).catch((err) =>{
    res.render("addEmployee", {departments: []}); 
  });
  //res.render('addEmployee');
});

app.get("/departments/add", (req,res) => {
  res.render('addDepartment');
});

app.get("/images", (req,res) => {
  fs.readdir(path.join(__dirname,"./public/images/uploaded"), function(err, iMages) {
      //res.json({images:iMages});
      res.render("images", {images:iMages}); 
  });
});

app.post("/images/add", upload.single("imageFile"), (req,res) =>{
  res.redirect("/images");
});

app.post("/employees/add", (req, res) => {
  data_serv.addEmployee(req.body).then(()=>{
    res.redirect("/employees");
  }).catch((err) => {res.status(500).send("Unable to Add Employee");})
});

app.post("/departments/add", (req, res) => {
  data_serv.addDepartment(req.body).then(()=>{
    res.redirect("/departments");
  }).catch((err) => {res.status(500).send("Unable to Add Department");})
});

app.post("/employee/update", (req, res) => {
  //console.log(req.body);
  data_serv.updateEmployee(req.body).then(()=>{
    res.redirect("/employees");
  }).catch((err)=>{
    res.status(500).send("Unable to Update Employee");
});

});

app.post("/department/update", (req, res) => {
  //console.log(req.body);
  data_serv.updateDepartment(req.body).then(()=>{
    res.redirect("/departments");
  });
});

app.use((req, res,next)=>{
    res.status(404).sendFile(path.join(__dirname,'views/404.html'));
 });


// app.listen(HTTP_PORT, onHttpStart);

data_serv.initialize().then(function(){
  app.listen(HTTP_PORT, onHttpStart);
}).catch(function(err){
  console.log("ERROR : " + err);
});
