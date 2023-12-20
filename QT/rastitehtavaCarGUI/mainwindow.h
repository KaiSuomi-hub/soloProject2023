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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//buttons below
private slots:
    void on_remove_clicked();
    void on_update_clicked();
    void on_add_clicked();
    void on_get_clicked();

    void getCarSlot (QNetworkReply *reply);
//read
    void on_refresh_clicked();
//post
    void addCarSlot (QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
//    Here we add the car class
    car *objectcar;
//    Let's go online
//read
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
//post
    QNetworkAccessManager *postManager;

};
#endif // MAINWINDOW_H
