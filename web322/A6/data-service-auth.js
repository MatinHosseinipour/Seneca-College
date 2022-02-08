var mongoose = require("mongoose"); //mongodb library
const bcrypt = require("bcryptjs"); //encrypt password
var Schema = mongoose.Schema;

//setting the userSchema
var userSchema = new Schema({
    "userName": {
        "type": String,
        "unique": true
    },
    "password": String,
    "email": String,
    "loginHistory": [{
        "dateTime": Date,
        "userAgent": String
    }]
});

let User; //defined on line initialize function

//connect to MongoDB
module.exports.initialize = function () {
    return new Promise(function (resolve, reject) {
        let db = mongoose.createConnection("");
        db.on('error', (err) => {
            reject(err); // reject the promise with the provided error
        });
        db.once('open', () => {
            User = db.model("users", userSchema);
            resolve();
        });
    });
};

//generates a new user receiving data from the register form.
//Sends encrypted password to db
module.exports.registerUser = (userData) => {
    return new Promise((resolve, reject) => {
        if (userData.password != userData.password2) {
            reject("Passwords do not match!");
        }
        else {
            bcrypt.genSalt(10, (err, salt) => {// Generate a "salt" using 10 rounds
                bcrypt.hash(userData.password, salt, (err, hash) => {
                    if (err) {
                        reject("There was an error encrypting the password")
                    }
                    else {
                        //Store the resulting "hash" value in the DB
                        userData.password = hash
                        let newUser = new User(userData);
                        newUser.save()
                            .then(() => { resolve(); }) //save successful
                            .catch((err) => { //problem in saving
                                if (err.code === 11000) { //if error code = 11000
                                    reject("Username already taken.");
                                }
                                else { //handling other errors
                                    reject(`There was an error creating the user: ${err}`);
                                }
                            })
                    }
                })
            })
        }
    })
}

//check user encrypted data. Resolve the data if verification is true
module.exports.checkUser = (userData) => {
    return new Promise((resolve, reject) => {
        User.find({ "userName": userData.userName })
            .then((users) => {
                bcrypt.compare(userData.password, users[0].password).then((res) => {
                    if (res === true) {
                        users[0].loginHistory.push({ dateTime: (new Date()).toString(), userAgent: userData.userAgent });
                        User.update(
                            { userName: userData.userName },
                            {
                                $set:
                                    { loginHistory: users[0].loginHistory }//fields
                            }//set                
                        )//update
                            .exec()
                            .then(() => {
                                resolve(users[0]);
                            })
                            .catch((err) => {
                                reject(`There was an error verifying the user: ${err}`);
                            })
                    } //if find
                    else {
                        reject(`Unable to find user: ${userData.userName}`);
                    }
                })
            }) //then of find 
            .catch((err) => {
                reject(`Unable to find user: ${userData.userName}`);
            })
    })
}