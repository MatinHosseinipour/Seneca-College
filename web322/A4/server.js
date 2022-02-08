/*********************************************************************************
*  WEB322 – Assignment 04
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part *  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
* 
*  Name: Matin Hosseini Pour Student ID: 151267192 Date: March 10th 2021
*  Online (Heroku) Link: http://hidden-anchorage-42358.herokuapp.com/
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
          res.render("employees", {employees:data});
      }).catch((err) => {
          //res.json({ message: err });
          res.render("employees", {message: err});
      });
  } else if (req.query.department) {
     data_serv.getEmployeesByDepartment(req.query.department).then((data) => {
          //res.json(data);
          res.render("employees", {employees:data});
      }).catch((err) => {
          //res.json({ message: err });
          res.render("employees", {message: err});
      });
  } else if (req.query.manager) {
      data_serv.getEmployeesByManager(req.query.manager).then((data) => {
          //res.json(data);
          res.render("employees", {employees:data});
      }).catch((err) => {
         // res.json({ message: err });
         res.render("employees", {message: err});
      });
  } else {
      data_serv.getAllEmployees().then((data) => {
          //res.json(data);
          res.render("employees", {employees:data});
      }).catch((err) => {
          //res.json({ message: err });
          res.render("employees", {message: err});
      });
  }
});

app.get("/employee/:empNum", (req, res) => {
  data_serv.getEmployeeByNum(req.params.empNum).then((data) => {
      //res.json(data);
      res.render("employee", { employee: data }); 
  }).catch((err) => {
      //res.json({message: err });
      res.render("employee",{message: err}); 
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
      res.render('departments', {departments:data});
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
  res.render('addEmployee');
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
  });
});
app.post("/employee/update", (req, res) => {
  //console.log(req.body);
  data_serv.updateEmployee(req.body).then(()=>{
    res.redirect("/employees");
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
