#-------------------------------------------------
#
# Project created by QtCreator 2015-01-29T11:05:38
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets
QT       += xml
QT       += widgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HorizontalLayout
TEMPLATE = app

CONFIG += C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    ticker.cpp \
    xmlPaser.cpp \
    MarqueeLabel.cpp \
    myitem.cpp \
    digitalclock.cpp \
    renderarea.cpp \
    wigglywidget.cpp \
    dragwidget.cpp \
    circlewidget.cpp \
    sidebar.cpp \
    SlidingStackedWidget.cpp \
    faderwidget.cpp


HEADERS  += mainwindow.h \
    ticker.h \
    MarqueeLabel.h \
    myitem.h \
    digitalclock.h \
    renderarea.h \
    wigglywidget.h \
    dragwidget.h \
    circlewidget.h \
    sidebar.h \
    SlidingStackedWidget.h \
    faderwidget.h


FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res.qrc

DISTFILES +=

