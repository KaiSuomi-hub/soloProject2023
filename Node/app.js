//16.12.2023
//Antti Suomi, syksy 2023 ohjelmaprojekti rästitehtävä
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

// var indexRouter = require('./routes/index');
// var usersRouter = require('./routes/users');

var app = express();

app.use(logger('dev'));
app.use(express.json());
// enable json
app.use(express.urlencoded({ extended: false }));

app.use(cookieParser());
// allow for  x-www-form-urlencoded
app.use(express.static(path.join(__dirname, 'public')));
// top level
// app.use('/', indexRouter);
// app.use('/users', usersRouter);
// books database
const bookRouter = require('./routes/book');
app.use('/book', bookRouter);
//stop injections and allow cross site scripting
const helmet = require('helmet');
const cors = require('cors');
//get token ignore signins
const jwt = require('jsonwebtoken');

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]

    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)

    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)

      if (err) return res.sendStatus(403)

      req.user = user

      next()
    })
  }

app.use(helmet());
app.use(cors());

// Exporting values with just the exports keyword is a quick way to export values from a module.
// You can use this keyword at the top or bottom, and all it does is populate the module.exports object.
module.exports = app;