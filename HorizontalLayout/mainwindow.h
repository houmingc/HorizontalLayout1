#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QDebug>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "MarqueeLabel.h"
#include "digitalclock.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include <QLCDNumber>
#include <QMovie>
#include <QStackedLayout>
#include <QComboBox>
#include <QWidget>
#include <QPropertyAnimation>
#include "QFrame"
#include <QList>

#include "wigglywidget.h"
#include "dragwidget.h"
#include <QLineEdit>
#include "circlewidget.h"
#include "sidebar.h"
#include "SlidingStackedWidget.h"

#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QCheckBox>
#include <QList>
#include "math.h"
#include "renderarea.h"
#include "QGraphicsOpacityEffect"
#include "faderwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void video();
    void CreateGuiControlComponents();
    void CreateMainLayout();
    void CreateSubSlidingWidgets();
    void CreateConnections();
    void CreateSlidingStackedWidget();
    ~MainWindow();

public slots:
    void move();
    void Opacity();
    void pictureRotate();
    void nextSlide1();
    void LabelPaused();
    void LabelMoving();
    void LabelEnd();
    void fadeInWidget(int);




private slots:
    void showTime1();
    void showTime2();

protected:

    QPushButton *buttonNext;
    QPushButton *buttonPrev;
    QCheckBox *checkWrap;
    QCheckBox *checkVertical;
    QSlider *slideSpeed;
    QComboBox *listAll;
    QLabel *speedLabel;
    QLCDNumber *speedDisplay;

    SlidingStackedWidget *slidingStacked;
    QVBoxLayout *mainLayout;
    QGridLayout *controlPaneLayout;
    QWidget *slideWidget1;
    QWidget *slideWidget2;
    QWidget *slideWidget3;
    QWidget *slideWidget4;

    int animTime;

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QVideoWidget* videoWidget;

    QMediaPlayer* player1;
    QMediaPlaylist* playlist1;
    QVideoWidget* videoWidget1;

    WidgetMarqueeLabel *ml;
    WidgetMarqueeLabel *mll;
    QLabel* label_destination;
    QLabel* label_source;

    QLabel* labelOneGif;
    QLabel* labelTwoGif;
    QLabel* page2_label1;
    QLabel* page2_label2;

    QLabel* colorlabel;
    QLabel* stationlabel;
    QLabel* separator;
    QHBoxLayout* Hlayout;
    RenderArea* renderArea;

    QPushButton* button1;
    QPalette* palette1;



    QLabel* page2_label3;
    QFrame* page2_line;
    QPalette* paletteRed;
    QString time_text;

    DigitalClock* DigitalLabel; //one
    QLabel* myTime1;
    QLabel* DateLabel1;
    QLabel* myTime2;
    QLabel* DateLabel2;  //one


    QLabel* gifmoving;
    QMovie* moviemoving;
    QPropertyAnimation* animation;

    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
    QHBoxLayout* topLayout;
    QVBoxLayout* centralLayout_p2;
    QGridLayout* WordLayout;
    QLabel* Station1;
    QLabel* Station2;
    QLabel* Station3;
    QLabel* page5_label;
    CircleWidget *circleWidgets[2][2];


    QVBoxLayout* rightLayout2;

    QVBoxLayout* Layout_page1;
    QVBoxLayout* Layout_page2;
    QHBoxLayout* Layout_page3;
    QGridLayout* Layout_page4;
    QVBoxLayout* Layout_page5;





    QStackedLayout* stackedLayout;
    QWidget* w_page1;
    QWidget* w_page2;
    QWidget* w_page3;
    QWidget* w_page4;
    QWidget* w_page5;
    QWidget* widgetCentral;
    QTimer* timer1;
    QGraphicsOpacityEffect* opacityEffect;


    //WidgetMarqueeLabel *mg;
    int currentSpeed;
    int xShift, yShift, scale, buttonSize;
    QList<QPushButton*> buttonList;
    void rearrangeButtons();


};


#endif // MAINWINDOW_H
