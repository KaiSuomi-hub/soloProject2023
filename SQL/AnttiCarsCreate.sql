USE netdb;

CREATE TABLE car(
id_car INT primary key auto_increment,
branch VARCHAR(255),
model VARCHAR(255)
);

INSERT INTO car(branch,model) VALUES('Lemon','Lada');
INSERT INTO car(branch,model) VALUES('Bitter','Ford');
