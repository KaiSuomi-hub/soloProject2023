//17.12.2023
//Antti Suomi, syksy 2023 ohjelmaprojekti rästitehtävä

// #include <string>
// #include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{

//destruction below
    delete ui;
//added deconsctructor as advised
    ui=nullptr;
//desctruct car() class
    delete objectcar;
    objectcar=nullptr;
}



//buttons below
void MainWindow::on_remove_clicked()
{
    QString id_car=ui->id_car->text();
    QString site_url="http://localhost:3000/car/"+id_car;
    qDebug()<<site_url;
    QNetworkRequest request(site_url);
    deleteManager = new QNetworkAccessManager(this);
    connect(deleteManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(deleteCarSlot(QNetworkReply*)));
    /* Delete is a reserved word in QT so thus the deleteresource*/
    reply = deleteManager->deleteResource(request);
}

void MainWindow::on_update_clicked()
{
    QJsonObject jsonObj;
    QString id_car=ui->id_car->text();
    QString site_url="http://localhost:3000/car/"+id_car;
    QString branch = ui->branch->text();
    QString model= ui->model->text();
    jsonObj.insert("branch",branch);
    jsonObj.insert("model",model);
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateCarSlot(QNetworkReply*)));
    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::on_add_clicked()
{
    QJsonObject jsonObj;
    QString branch = ui->branch->text();
    QString model= ui->model->text();
    jsonObj.insert("branch",branch);
    jsonObj.insert("model",model);
    QString site_url="http://localhost:3000/car/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addCarSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::on_get_clicked()
{
    QString id_car=ui->id_car->text();
    QString site_url="http://localhost:3000/car/"+id_car;
    qDebug()<<site_url;
    QNetworkRequest request(site_url);
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCarSlot(QNetworkReply*)));
    reply = getManager->get(request);
}
//this is for an array, which we get when we call for the root of car

void MainWindow::on_refresh_clicked()
{
    QString site_url="http://localhost:3000/car";
    QNetworkRequest request((site_url));
    // We don't use auths, etkö sä tiiä kuka mä oon?
    // //WEBTOKEN ALKU
    // QByteArray myToken="Bearer xRstgr...";
    // request.setRawHeader(QByteArray("Authorization"),(myToken));
    // //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);
    /*
     * This line below establishes a connection between the finished(QNetworkReply*) signal of the getManager
     * and the getCarSlot(QNetworkReply*) slot of the current MainWindow object.
     * This connection indicates that when the HTTP request is finished,
     * the getCarSlot function will be called to handle the response.
     *
    */
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCarSlot(QNetworkReply*)));
    reply = getManager->get(request);

}

void MainWindow::getCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    //let's print out what we get for curiosity's sake as raw
    ui->status->setText(response_data);
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString car;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        car+=QString::number(json_obj["id_car"].toInt())+", "+json_obj["branch"].toString()+", "+json_obj["model"].toString()+"\r";
    }
    ui->carList->setText(car);
    reply->deleteLater();
    getManager->deleteLater();
}


void MainWindow::addCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    //let's print out what we get for curiosity's sake as raw
    ui->status->setText(response_data);
    reply->deleteLater();
    postManager->deleteLater();
}

void MainWindow::updateCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    //let's print out what we get for curiosity's sake as raw
    ui->status->setText(response_data);
    reply->deleteLater();
    putManager->deleteLater();
}

void MainWindow::deleteCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    //let's print out what we get for curiosity's sake as raw
    ui->status->setText(response_data);
    reply->deleteLater();
    deleteManager->deleteLater();
}
