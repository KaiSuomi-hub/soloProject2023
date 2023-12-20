//16.12.2023
//Antti Suomi, syksy 2023 ohjelmaprojekti rästitehtävä

const express = require('express');
const router = express.Router();
const car = require('../models/car_model');

//list all
router.get('/',
    function (request, response) {
        car.getAll(function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        })
    });
//read by id
router.get('/:id',
    function (request, response) {
        car.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        })
    });

//create by id
router.post('/',
function(request, response) {
  car.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

// delete by id
router.delete('/:id',
function(request, response) {
  car.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

//and update by id
router.put('/:id',
function(request, response) {
  car.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;