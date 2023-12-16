//16.12.2023
//Antti Suomi, syksy 2023 ohjelmaprojekti rästitehtävä*/

const mysql = require('mysql2');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'netuser',
  password: 'netpass',
  database: 'netdb'
});
module.exports = connection;