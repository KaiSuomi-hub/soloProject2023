//17.12.2023
//Antti Suomi, syksy 2023 ohjelmaprojekti rästitehtävä

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
