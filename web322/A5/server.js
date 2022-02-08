var express = require("express");
var app = express();
const ds = require("./data-service.js");
const path = require("path");
const multer = require("multer");
const fs = require('fs');
const bodyParser = require('body-parser');
const exphbs = require("express-handlebars");
const HTTP_PORT = process.env.PORT || 8080;

function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}

const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filename: function (req, file, cb) {
      cb(null, Date.now() + path.extname(file.originalname));
    }
  });

const upload = multer({ storage: storage });

app.use(express.static("public"));
app.use(bodyParser.urlencoded({ extended: true }));

app.use(function(req,res,next){
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
});

app.engine(".hbs", exphbs({ 
    extname: ".hbs",
    defaultLayout: 'main',
    helpers:{
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
app.set("view engine", ".hbs");

app.get("/", function(req, res) {
    res.render('home', {});
});

app.get("/about", function(req, res) {
    res.render('about', {});
});

app.get("/employees/add", function(req, res) {
    ds.getDepartments().then((data) => {
        res.render("addEmployee", {departments: data});
    }).catch((err)=>{
        res.render("addEmployee", {departments: []});
    });
});

app.post("/employees/add", (req, res) => {
    ds.addEmployee(req.body).then(()=>{
        res.redirect("/employees");
    }).catch((rejectMsg) => {
        res.status(500).send("Unable to add employee");
    }); 
});

app.get("/images/add", function(req, res) {
    res.render('addImage', {});
});

app.post("/images/add", upload.single("imageFile"), (req, res) => {
    res.redirect("/images");
});

app.get("/images", function(req, res) {
    let path = "./public/images/uploaded";
     
    fs.readdir(path, function(err, items) {
        res.render('images', {
            images: items
        }); 
    });
});

app.get("/employees", function(req, res) {
    if(req.query.status){
        ds.getEmployeesByStatus(req.query.status)
        .then((data) => {
            if (data.length > 0)
                res.render('employees',{employees: data.map(value => value.dataValues)});
            else
                res.render('employees',{ message: "No results" });
        })
        .catch((rejectMsg) => {
            res.status(500).send("No results");
         });
    }
    else if(req.query.department){
        ds.getEmployeesByDepartment(req.query.department)
        .then((data) => {
            if (data.length > 0)
                res.render('employees',{employees: data.map(value => value.dataValues)});
            else
                res.render('employees',{ message: "No results" });
        })
        .catch((rejectMsg) => {
            res.status(500).send("No results");
         });
    }
    else if(req.query.manager){
        ds.getEmployeesByManager(req.query.manager)
        .then((data) => {
            if (data.length > 0)
                res.render('employees',{employees: data.map(value => value.dataValues)});
            else
                res.render('employees',{ message: "No results" });
        })
        .catch((rejectMsg) => {
            res.status(500).send("No results");
         });
    }
    else {
        ds.getAllEmployees()
        .then((data) => {
            if (data.length > 0){
                res.render('employees',{employees: data.map(value => value.dataValues)});
                
            }
            else {
                res.render('employees',{ message: "No results" });
            }
        })
        .catch((rejectMsg) => {
            res.status(500).send("No results");
        });
    }
});

app.get("/employee/:empNum", (req, res) => {
    // initialize an empty object to store the values
    let viewData = {};

    ds.getEmployeeByNum(req.params.empNum).then((data) => {
        if (data) {
            viewData.employee = data; //store employee data in the "viewData" object as "employee"
        } else {
            viewData.employee = null; // set employee to null if none were returned
         }
    }).catch(() => {
        viewData.employee = null; // set employee to null if there was an error
    }).then(ds.getDepartments)
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

app.post("/employee/update", (req, res) => {
    ds.updateEmployee(req.body)
    .then((data) => { 
        res.redirect("/employees");
    })
    .catch((rejectMsg) => {
        res.status(500).send("Unable to update employee"); //check
    }); 
});
  
app.get("/employees/delete/:empNum", (req,res)=>{
    ds.deleteEmployeeByNum(req.params.empNum).then(()=>{
        res.redirect("/employees");
    }).catch((rejectMsg)=>{
        res.status(500).send("Unable to Remove Employee / Employee not found");
    });
});

app.get("/departments", function(req, res) {
    ds.getDepartments()
    .then((data) => {
        if (data.length > 0){
            res.render("departments", {departments: data});
        }
        else
            res.render("departments",{ message: "No results" });
    })
    .catch((rejectMsg) => {
        res.status(500).send("No results");
    });
});

app.get("/departments/add", function(req, res) {
    ds.getDepartments().then((data) => {
        res.render("addDepartment", {departments: data});
    }).catch((err)=>{
        res.render("addDepartment", {departments: []});
    });
});

app.post("/departments/add", (req, res) => {
    ds.addDepartment(req.body).then(()=>{
        res.redirect("/departments");
    }).catch((rejectMsg) => {
        res.status(500).send("Unable to add department");
    });
});

app.post("/department/update", (req, res) => {
    ds.updateDepartment(req.body)
    .then(() => { 
        res.redirect("/departments");
    })
    .catch((rejectMsg) => {
        res.status(500).send("No results");
    }); 
});

app.get("/department/:departmentId", function(req, res) {
    ds.getDepartmentById(req.params.departmentId)
    .then((data) => { 
        if (data){
            res.render("department", {department: data});
        }
        else{
            res.status(404).send("Department Not Found");
        }
    })
    .catch((rejectMsg) => {
        res.status(404).send("Department Not Found");
    });
});

app.use((req, res) => {
    res.status(404).send("Page Not Found");
});

ds.initialize()
.then(() => {
    app.listen(HTTP_PORT, onHttpStart)
})
.catch((rejectMsg) => {
    console.log(rejectMsg);
});