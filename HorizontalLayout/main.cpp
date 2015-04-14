#include "mainwindow.h"
#include <QApplication>
#include <QtXml>
#include <QDebug>
#include <QtCore>
#include <QFile>
#include "xmlPaser.cpp"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(xmlPaser())
    {
        qDebug()<<"cannot read xml";
    }

    MainWindow w;


    return a.exec();
}
