//17.12.2023
//Antti Suomi, syksy 2023 ohjelmaprojekti rästitehtävä

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <car.h>
#include <QDialog>
#include <QtNetwork/QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
/*
 *
 *Public
 *
 */
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//buttons below
 /*
 *
 *Private Slots
 *
 */
private slots:
    void on_remove_clicked();
    void on_update_clicked();
    void on_add_clicked();
    void on_get_clicked();
    void getCarSlot (QNetworkReply *reply);
//read
    void on_refresh_clicked();
//create
    void addCarSlot (QNetworkReply *reply);
// update
    void updateCarSlot (QNetworkReply *reply);
// delete
    void deleteCarSlot (QNetworkReply *reply);

//id

 /*
 *
 *Private
 *s
 */
private:
    Ui::MainWindow *ui;
//    Here we add the car class
    car *objectcar;
// form fields and values


//    Let's go online
//read
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
//create
    QNetworkAccessManager *postManager;
//update
    QNetworkAccessManager *putManager;
//delete
    QNetworkAccessManager *deleteManager;


};
#endif // MAINWINDOW_H
