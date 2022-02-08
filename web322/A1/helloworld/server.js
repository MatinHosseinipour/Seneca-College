/*********************************************************************************
*  WEB322 – Assignment 1
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: Matin Hosseini Pour Student ID: 151267192 Date: Jan 17th, 2021
*
*  Online (Heroku) URL: https://polar-headland-34051.herokuapp.com/
*
********************************************************************************/ 

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();

// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    res.send("Matin Hosseini Pour. 151267192");
});

// setup http server to listen on HTTP_PORT
app.listen(HTTP_PORT);