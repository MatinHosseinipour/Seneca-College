const exphbs = require("express-handlebars")
const dataServiceAuth = require('./data-service-auth');
var data = require("./data-service") //requiring all functions from data-service.js
var clientSessions = require("client-sessions")
var express = require("express")
var path = require("path")
var multer = require("multer") //deal with images
var bodyParser = require("body-parser") //deal with forms
var app = express() //start an express app
var fs = require("fs") //fs.readdir
const { resolve } = require("path")
app.use(express.static('public')); //set the public dir as static
app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: 'main',
    helpers: {
        navLink: function (url, options) {
            return '<li' +
                ((url == app.locals.activeRoute) ? ' class="active" ' : '') + '><a href="' + url + '">' + options.fn(this) + '</a></li>';
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
})); //process .hbs files
app.set('view engine', '.hbs');
app.use(express.static(path.join(__dirname, 'views'))) //set the views dir as static
app.use(bodyParser.urlencoded({ extended: true }))

var HTTP_PORT = process.env.PORT || 8080

//setting the disk storage
const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filename: function (req, file, cb) {
        cb(null, Date.now() + path.extname(file.originalname))
    }
})
const upload = multer({ storage: storage });

//setting the active
app.use(function (req, res, next) {
    let route = req.baseUrl + req.path; app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
})

//setting client-session
app.use(clientSessions({
    cookieName: "session",  // cookie name dictates the key name added to the request object
    secret: "web322_a6", //long and unguessable string
    duration: 2 * 60 * 1000, //2 mintues duration in ms
    activeDuration: 1000 * 60 //session extension by each request
}))

//templates will have access to a session object = {{session.userName}}
app.use(function(req, res, next) {
    res.locals.session = req.session;
    next();
    });

//helper middleware function to ensureLogin. if user is not logged in, redirect to the login page
ensureLogin = (req, res, next) => {
    if(!req.session.user){
        res.redirect("/login");
    }
    else {
        next();
    }
}

// *************************************
// ************ GET ROUTES *************
// *************************************
//sending the home page
app.get("/", function (req, res) {
    res.render(path.join(__dirname, "views/home.hbs"))
})

//sending the about page
app.get("/about", function (req, res) {
    res.render(path.join(__dirname, "views/about.hbs"))
})

// ********** GET EMPLOYEES ************
//employees route
app.get("/employees", ensureLogin, function (req, res) {
    //getting employees by status
    if (req.query.status) {
        data.getEmployeesByStatus(req.query.status)
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "No results returned." })
            }).catch((err) => {
                res.render({ message: "No results returned." });
            })
    }

    //getting employees by department
    else if (req.query.department) {
        data.getEmployeesByDepartment(req.query.department)
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "No results returned." })
            }).catch((err) => {
                res.render({ message: "no results" });
            })
    }

    //getting employees by manager id
    else if (req.query.manager) {
        data.getEmployeesByManager(req.query.manager)
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "No results returned." })
            }).catch((err) => {
                res.render({ message: "no results" })
            })
    }

    //getting all employees
    else {
        data.getAllEmployees()
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "No results returned." })
            })
            .catch((err) => {
                res.render({ message: "no results" })
            })
    }
})

//get employee by id
app.get("/employee/:empNum", ensureLogin, (req, res) => {
    // initialize an empty object to store the values
    let viewData = {};
    data.getEmployeeByNum(req.params.empNum).then((data) => {
        if (data) {
            viewData.employee = data; //store employee data in the "viewData" object as "employee"
        } else {
            viewData.employee = null; // set employee to null if none were returned
        }
    }).catch(() => {
        viewData.employee = null; // set employee to null if there was an error
    }).then(data.getDepartments)
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

//route to load the page with the form to add a new employee
app.get("/employees/add", ensureLogin, (req, res) => {
    data.getDepartments()
        .then((data) => {
            res.render("addEmployee", { departments: data })
        })
        .catch((err) => {
            res.render("addEmployee", { departments: [] });
        })
    //res.render(path.join(__dirname, "/views/addEmployee.hbs"))
})

//delete employee by id
app.get("/employees/delete/:empNum", ensureLogin, (req, res) => {
    data.deleteEmployeeByNum(req.params.empNum)
        .then(() => {
            res.redirect("/employees");
        }).catch((err) => {
            res.status(500).send("Unable to Remove Employee / Employee not found");
        })
})

// ********** GET DEPARTMENTS ************
//delete department by id
app.get("/departments/delete/:depNum", ensureLogin, (req, res) => {
    data.deleteDepartmentByNum(req.params.depNum)
        .then(() => {
            res.redirect("/departments");
        }).catch((err) => {
            res.status(500).send("Unable to Remove Employee / Employee not Found");
        })
})

//route to get the add for departments
app.get("/departments/add", ensureLogin, (req, res) => {
    res.render(path.join(__dirname, "/views/addDepartment.hbs"))
})

//departments route
app.get("/departments", ensureLogin, function (req, res) {
    data.getDepartments()
        .then((data) => {
            res.render("departments", { departments: data })
        })
        .catch(err => res.status(404).send('departments not found'))
})

//departments by id
app.get("/department/:departmentId", ensureLogin, (req, res) => {
    data.getDepartmentById(req.params.departmentId)
        .then((data) => {
            res.render("department", { department: data });
        }).catch((err) => {
            res.status(404).send("Department Not Found")
        }
        )
})

// ********** GET IMAGES ************
//route to load the page with all the images in a json format
app.get("/images", ensureLogin, (req, res) => {
    fs.readdir("./public/images/uploaded", (err, image) => {
        res.render("images", { "images": image });
    })
})

////route to load the page with the form to add a new image
app.get("/images/add", ensureLogin, (req, res) => {
    res.render(path.join(__dirname, "/views/addImage.hbs"))
})

// ********** GET SESSIONS ************
//render login view
app.get("/login", (req, res) => {
    res.render("login");
})

//render register view
app.get("/register", (req, res) => {
    res.render("register");
})

//get logout
app.get("/logout", (req, res) => {
    req.session.reset(); //reset current session
    //redirect to the home page
    res.redirect("/");
})

//get user history
app.get("/userHistory", ensureLogin, (req, res) => {
    res.render("userHistory");
})

// *************************************
// ************ POST ROUTES ************
// *************************************

// ********** POST EMPLOYEES ***********
//post to employees adding
app.post("/employees/add", ensureLogin, (req, res) => {
    data.addEmployee(req.body)
        .then(() => {
            res.redirect('/employees');
        }).catch((err) => {
            res.status(500).send("Unable to Update Employee");
        })
})

//post to update employee
app.post("/employee/update", ensureLogin, (req, res) => {
    data.updateEmployee(req.body)
        .then((data) => {
            res.redirect("/employees")
        })
        .catch((err) => {
            console.log(err)
        })
});

// ********** POST DEPARTMENTS *********
//post to departments adding
app.post("/departments/add", ensureLogin, (req, res) => {
    data.addDepartment(req.body)
        .then(() => { res.redirect('/departments') })
        .catch((err) => { message: err });
})

//post to update department
app.post("/departments/update", ensureLogin, (req, res) => {
    data.updateDepartment(req.body)
        .then(() => {
            res.redirect("/departments")
        })
        .catch((err) => {
            console.log(err)
        })
});

// ********** POST IMAGES **************
//post to image adding
app.post("/images/add", upload.single('imageFile'), ensureLogin, (req, res) => {
    res.redirect('/images')
})

// ********** POST SESSIONS ************
//post the register form
app.post("/register", (req, res) => {
    dataServiceAuth.registerUser(req.body)
    .then(()=> {
        res.render("register", {successMessage: "User created"});
    })
    .catch((err)=> {
        res.render("register", {errorMessage: err, userName: req.body.userName});
    })
})

//post login form
app.post("/login", (req, res) => {
    req.body.userAgent = req.get('User-Agent');
    dataServiceAuth.checkUser(req.body)
    .then((user)=> {
        //add the user data to the current session
        req.session.user = {
            userName: user.userName,
            email: user.email,
            loginHistory: user.loginHistory
        }
        res.redirect("/employees");
    })
    .catch((err) => {
        res.render("login", {errorMessage: err, userName: req.body.userName});
    })
})


//all the other paths, send the not found page
app.get("*", function (req, res) {
    res.render(path.join(__dirname, "views/notfound.hbs"), { layout: false })
})


//first read the data, then if it returns a resolve, it loads the server
data.initialize()
    .then(dataServiceAuth.initialize)
    .then(() => {
        app.listen(HTTP_PORT, () => {
            console.log("Express http server listening on port http://localhost:" + HTTP_PORT)
        })
    }).catch((err) => {
        console.log(err)
    });

