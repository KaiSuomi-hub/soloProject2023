//17.12.2023
//Antti Suomi, syksy 2023 ohjelmaprojekti rästitehtävä

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
//added deconsctructor
    ui=nullptr;
}



void MainWindow::on_remove_clicked()
{

}


void MainWindow::on_update_clicked()
{

}


void MainWindow::on_add_clicked()
{

}


void MainWindow::on_get_clicked()
{

}

