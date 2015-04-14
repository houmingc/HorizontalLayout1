#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "ticker.h"
#include <QMainWindow>
#include <iostream>
#include <QMediaPlaylist>
#include <QTimer>
#include <QDateTime>
#include "digitalclock.h"
#include <QImage>
#include "renderarea.h"
#include <QPushButton>
#include "faderwidget.h"

int counter = 15;

extern QStringList xmlID;
extern QStringList xmlName;
extern QStringList xmlValue;
extern MainWindow MainWindow;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    buttonSize =50;
    scale =100;
    xShift= 100;
    yShift =100;
    ui->setupUi(this);

    ml = new WidgetMarqueeLabel();
    ml->setDirection(1);
    ml->setSpeed(1);
    ml->setText(QString("%1").arg(xmlValue[2]));
    ml->setFont(QFont("Arial", 15,30));


    video();
    QFont f("Arial",19, QFont::Bold);
    QFont g("Arial",23, QFont::Bold);
    QFont h("Arial",33, QFont::Bold);

    DigitalLabel= new DigitalClock();
    DigitalLabel->setFont(f);
    DigitalLabel->setStyleSheet("QLabel { color : red; }");

    //show time every minutes
    myTime1 = new QLabel;
    myTime1->setFont(f);
    myTime1->setAlignment(Qt::AlignCenter);
    myTime1->setStyleSheet("QLabel { color : white; }");
    QTimer *clocktimer1 = new QTimer(this);
    connect(clocktimer1,SIGNAL(timeout()),this,SLOT(showTime1()));
    clocktimer1->start();

    //show time every minutes
    myTime2 = new QLabel;
    myTime2->setFont(f);
    myTime2->setAlignment(Qt::AlignRight);
    myTime2->setStyleSheet("QLabel { color : red; }");
    QTimer *clocktimer2 = new QTimer(this);
    connect(clocktimer2,SIGNAL(timeout()),this,SLOT(showTime2()));
    clocktimer2->start();

    //show date
    DateLabel1 = new QLabel;
    //QDateTime dateTime = QDateTime::currentDateTime();
    QDate dateTime1 = QDate::currentDate();
    QString datetimetext = dateTime1.toString("d MMMM yy");
    DateLabel1->setText(datetimetext);
    DateLabel1->setFont(f);
    DateLabel1->setAlignment(Qt::AlignCenter);
    DateLabel1->setStyleSheet("QLabel { color : white; }");

    //show date
    DateLabel2 = new QLabel;
    //QDateTime dateTime = QDateTime::currentDateTime();
    QDate dateTime2 = QDate::currentDate();
    QString datetimetext2 = dateTime2.toString("d MMMM yy");
    DateLabel2->setText(datetimetext2);
    DateLabel2->setFont(f);
    DateLabel2->setAlignment(Qt::AlignRight);
    DateLabel2->setStyleSheet("QLabel { color : red; }");

    // 1st component
    labelOneGif = new QLabel;
    QMovie *movie_one = new QMovie(":/name/coolani.gif");
    labelOneGif->setAlignment(Qt::AlignCenter);
    labelOneGif->setMovie(movie_one);
    movie_one->start();

    // 2rd component
    label_destination = new QLabel(tr("   11 Woodland North"));
    label_destination->setFont(f);
    label_destination->setAlignment(Qt::AlignCenter);
    label_destination->setStyleSheet("QLabel { color : white; }");

    // 3rd component
    labelTwoGif = new QLabel;
    QMovie *movie_two = new QMovie(":/name/clogo.gif");
    labelTwoGif->setMovie(movie_two);
    labelTwoGif->setAlignment(Qt::AlignCenter);
    labelTwoGif->setGeometry(10,10,10,10);
    movie_two->start();


    // 4th component
    label_source = new QLabel(tr(" 13 Stevens"));
    label_source->setFont(f);
    label_source->setAlignment(Qt::AlignCenter);
    label_source->setStyleSheet("QLabel { color : white; }");


    leftLayout = new QVBoxLayout();
    //leftLayout->setAlignment(Qt::AlignCenter);
    //leftLayout->setAlignment(Qt::AlignHCenter);
    //leftLayout->setAlignment(Qt::AlignVCenter);
    leftLayout->addWidget(DateLabel1);
    leftLayout->addWidget(labelOneGif);
    leftLayout->addSpacing(3);
    //leftLayout->addStretch(0.1);
    leftLayout->addWidget(label_destination);
    leftLayout->addSpacing(3);
    //leftLayout->addStretch(0.1);
    leftLayout->addWidget(labelTwoGif);
    leftLayout->addSpacing(3);
    //leftLayout->addStretch(0.1);
    leftLayout->addWidget(label_source);
    leftLayout->addWidget(myTime1);

    rightLayout = new QVBoxLayout();
    rightLayout->addWidget(videoWidget);


    topLayout = new QHBoxLayout();
    topLayout->addLayout(leftLayout);
    topLayout->addLayout(rightLayout);

    Layout_page1= new QVBoxLayout();
    Layout_page1->addLayout(topLayout);
    Layout_page1->addWidget(ml);




    // 1st horizontal component

    button1 = new QPushButton();
    palette1->setColor(QPalette::Button, Qt::red);
    button1->setPalette(*palette1);







//     QPixmap pm(50,50);
//     pm.fill();
//     QPainter p(&pm);
//     p.setRenderHint(QPainter::Antialiasing,true);
//     QPen pen(Qt::red, 1);
//     p.setPen(pen);
//    p.drawEllipse(0,0,80,80);
//     QLabel* l = new QLabel;
//     l->setPixmap(pm);


    // 2rd horizontal component
    stationlabel = new QLabel(tr(" THOMSON LINE "));
    stationlabel->setFont(f);
    stationlabel->setStyleSheet("QLabel { color : red; }");
    stationlabel->setAlignment(Qt::AlignLeft);

    // 3rd horizontal component
    separator = new QLabel(tr(" | "));
    separator->setFont(f);
    separator->setStyleSheet("QLabel { color : red; }");
    separator->setAlignment(Qt::AlignRight);

    Hlayout = new QHBoxLayout();
    Hlayout->addWidget(button1);
    Hlayout->addWidget(stationlabel);
    Hlayout->addWidget(myTime2);
    Hlayout->addWidget(separator);
    Hlayout->addWidget(DateLabel2);


    QTimer::singleShot(12000,this,&MainWindow::Opacity);



    page2_label1= new QLabel("NEXT TRAIN");
    page2_label1->setAlignment(Qt::AlignCenter);
    page2_label1->setFont(g);
    page2_label1->setStyleSheet("QLabel { color : red; }");

    page2_label2= new QLabel("2 mins");
    page2_label2->setAlignment(Qt::AlignCenter);
    page2_label2->setFont(h);
    page2_label2->setStyleSheet("QLabel { color : red; }");


    page2_label3 = new QLabel("WOODLAND NORTH");
    page2_label3->setAlignment(Qt::AlignCenter);
    page2_label3->setFont(g);
    page2_label3->setStyleSheet("QLabel { color : red; }");
    gifmoving = new QLabel;

    QPalette paletteRed;
    paletteRed.setColor(QPalette::WindowText,Qt::red);
    page2_line = new QFrame();
    page2_line->setFrameShape(QFrame::HLine);
    page2_line->setPalette(paletteRed);
    page2_line->setLineWidth(5);



    Station1= new QLabel("SpringLeaf");
    Station1->setStyleSheet("QLabel { color : green; }");
    Station1->setFont(QFont("Trebuchet",12,QFont::Bold));

    Station2= new QLabel("Lentor");
    Station2->setStyleSheet("QLabel { color : green; }");
    Station2->setFont(QFont("Trebuchet",12,QFont::Bold));

    Station3= new QLabel("Mayflower");
    Station3->setStyleSheet("QLabel { color : green; }");
    Station3->setFont(QFont("Trebuchet",12,QFont::Bold));


    WordLayout = new QGridLayout();
    WordLayout->addWidget(Station1,0,0, Qt::AlignLeft);
    WordLayout->addWidget(Station2,0,1, Qt::AlignCenter);
    WordLayout->addWidget(Station3,0,2, Qt::AlignRight);

    //secondPageWidget->showMaximized();
    Layout_page2= new QVBoxLayout();
    Layout_page2->addLayout(Hlayout);
    Layout_page2->addWidget(page2_label1);
    Layout_page2->addSpacing(2);
    Layout_page2->addWidget(page2_label2);
    Layout_page2->addSpacing(2);
    Layout_page2->addWidget(page2_label3);
    Layout_page2->addSpacing(2);
    Layout_page2->addWidget(page2_label3);
    Layout_page2->addWidget(page2_line);
    Layout_page2->addLayout(WordLayout);
    Layout_page2->addWidget(gifmoving);



    WigglyWidget *wigglyWidget = new WigglyWidget;
    QLineEdit *lineEdit = new QLineEdit;
    connect(lineEdit, &QLineEdit::textChanged, wigglyWidget, &WigglyWidget::setText);
    lineEdit->setText(tr("Happy Day Passenger Everyday"));

    SideBar *w = new SideBar;
    w->addAction("SideBar1");
    w->addAction("SideBar2");
    w->addAction("SideBar3");

    rightLayout2 = new QVBoxLayout(this);
    rightLayout2->addWidget(wigglyWidget);
    rightLayout2->addWidget(new DragWidget);


    Layout_page3 = new QHBoxLayout(this);
    Layout_page3->addWidget(w);



    Layout_page4 = new QGridLayout(this);
    QTimer *timer = new QTimer(this);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            circleWidgets[i][j] = new CircleWidget;
            circleWidgets[i][j]->setAntialiased(true);
            circleWidgets[i][j]->setFloatBased(true);
            connect(timer, SIGNAL(timeout()),
                    circleWidgets[i][j], SLOT(nextAnimationFrame()));

            Layout_page4->addWidget(circleWidgets[i][j], i + 1, j + 1);
        }
    }
    timer->start(50);



            page5_label= new QLabel();
            page5_label->setPixmap(QPixmap(":/cartopView.png"));

          Layout_page5 = new QVBoxLayout(this);
          Layout_page5->addWidget(page5_label);

       w_page1 = new QWidget;
       w_page2 = new QWidget;
       w_page3 = new QWidget;
       w_page4 = new QWidget;
       w_page5 = new QWidget;

       w_page1->setLayout(Layout_page1);
       w_page1->showMaximized();
       w_page1->setStyleSheet("background-color:black");
       w_page2->setLayout(Layout_page2);
       w_page2->showMaximized();
       w_page2->setStyleSheet("background-color:black");

       w_page3->setLayout(Layout_page3);
       w_page3->showMaximized();
       w_page3->setStyleSheet("background-color:white");
       w_page4->setLayout(Layout_page4);
       w_page4->showMaximized();
       w_page4->setStyleSheet("background-color:white");

       w_page5->setLayout(Layout_page5);
       w_page5->showMaximized();
       w_page5->setStyleSheet("background-color:white");

    //QVBoxLayout *Layout_total = new QVBoxLayout;
    stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(w_page1);
    stackedLayout->addWidget(w_page2);
    stackedLayout->addWidget(w_page3);
    stackedLayout->addWidget(w_page4);
    stackedLayout->addWidget(w_page5);



    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(nextSlide1()));
    timer1->start(12000);


    moviemoving = new QMovie(":/name/index.jpeg");
    gifmoving->setMovie(moviemoving);
    gifmoving->setFixedSize(80,40);
    moviemoving->start();
    //QTimer fires after 12sec, since each slides is 12 sec
    //
    QTimer::singleShot(12000,this,&MainWindow::move);
    QTimer::singleShot(15000,this,&MainWindow::LabelPaused);  //pause message
    QTimer::singleShot(18000,this,&MainWindow::LabelMoving);  //2rd segment moving message
    QTimer::singleShot(20000,this,&MainWindow::LabelEnd);  //end message
    QTimer::singleShot(60000,this,&MainWindow::pictureRotate);

}




//create a new mediaplaylist, mediaplayer, Videowidget, playlist

void MainWindow::video()
{
    QString RealVideo1=xmlValue[0];
    playlist= new QMediaPlaylist();
    player= new QMediaPlayer();
    videoWidget = new QVideoWidget();
    playlist->addMedia(QUrl::fromLocalFile(RealVideo1));
    playlist->addMedia(QUrl::fromLocalFile("/opt/V7.mp4"));
    playlist->addMedia(QUrl::fromLocalFile("/opt/hotgirl.mp4"));
    playlist->addMedia(QUrl::fromLocalFile("/opt/bird.mp4"));
    playlist->addMedia(QUrl::fromLocalFile("/opt/arrow.mp4"));

    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->setCurrentIndex(1);

    player->setPlaylist(playlist);
    player->setVolume(100);

//    QRectF rect= QRectF(0,0,100,100);

//    QPainterPath path;
//    path.moveTo(rect.left(),rect.top());
//    path.lineTo(rect.bottom());
//    path.lineTo(rect.right());

//    QPainter painter;
//    painter.setPen(Qt:: NoPen);
//    painter.fillPath(path, QBrush(QColor("blue")) );


    QString RealVideo2=xmlValue[1];
    playlist1= new QMediaPlaylist();
    playlist1->setPlaybackMode(QMediaPlaylist::Loop);
    player1= new QMediaPlayer;
    videoWidget1 = new QVideoWidget;
    playlist1->addMedia(QUrl::fromLocalFile(RealVideo2));
    player1->setPlaylist(playlist1);
    player1->setVolume(0);


    player->setVideoOutput(videoWidget);
    player1->setVideoOutput(videoWidget1);

    playlist->setCurrentIndex(1);
    player->play();

}

//void MainWindow::CreateGuiControlComponents()
//{
//    int _min=500;
//    int _max=1500;
//    animTime=(_min+_max)>>1;

//    buttonNext = new QPushButton(tr("Next"));
//    buttonPrev = new QPushButton(tr("Prev"));
//    checkWrap = new QCheckBox(tr("Wrap"));
//    checkVertical = new QCheckBox(tr("Vertical"));

//    listAll = new QComboBox();
//    listAll->addItem(tr("Page 1"));
//    listAll->addItem(tr("Page 2"));
//    listAll->addItem(tr("Page 3"));
//    listAll->addItem(tr("Page 4"));
//    listAll->setMinimumHeight ( 40 );

//    speedLabel = new QLabel(tr("Anim. Time:"));
//    speedDisplay= new QLCDNumber();

//    slideSpeed = new QSlider(Qt::Horizontal);
//    slideSpeed->setMinimum(_min);
//    slideSpeed->setMaximum(_max);

//    //initialize slider and its display
//    slideSpeed->setValue(animTime);
//    speedDisplay->display(animTime);
//}

//void MainWindow::CreateMainLayout()
//{

//    Layout_page5 = new QVBoxLayout();
//    controlPaneLayout=new QGridLayout();
//    Layout_page5->addWidget(slidingStacked);
//    Layout_page5->addLayout(controlPaneLayout);
//    int row;
//    row=1;
//    controlPaneLayout->addWidget(buttonPrev,row,1,1,1);
//    controlPaneLayout->addWidget(buttonNext,row,2,1,1);
//    controlPaneLayout->addWidget(checkWrap,++row,1,1,1);
//    controlPaneLayout->addWidget(checkVertical,row,2,1,1);
//    controlPaneLayout->addWidget(speedLabel,++row,1,1,1);
//    controlPaneLayout->addWidget(speedDisplay,row,2,1,1);
//    controlPaneLayout->addWidget(slideSpeed,++row,1,1,2);
//    controlPaneLayout->addWidget(listAll,++row,1,1,2);


//}

//void MainWindow::CreateSubSlidingWidgets()
//{
//    slideWidget1=new QWidget();
//    slideWidget2=new QWidget();
//    slideWidget3=new QWidget();
//    slideWidget4=new QWidget();
//    QVBoxLayout *slideWidget1layout=new QVBoxLayout();
//    slideWidget1->setLayout(slideWidget1layout);
//    QVBoxLayout *slideWidget2layout=new QVBoxLayout();
//    slideWidget2->setLayout(slideWidget2layout);
//    QVBoxLayout *slideWidget3layout=new QVBoxLayout();
//    slideWidget3->setLayout(slideWidget3layout);
//    QVBoxLayout *slideWidget4layout=new QVBoxLayout();
//    slideWidget4->setLayout(slideWidget4layout);
//    QPushButton *b11=new QPushButton("Qt");
//    slideWidget1layout->addWidget(b11);
//    QPushButton *b12=new QPushButton("is cool !");
//    slideWidget1layout->addWidget(b12);

//    QPushButton *b21=new QPushButton("Cool");
//    slideWidget2layout->addWidget(b21);
//    QPushButton *b22=new QPushButton("is Qt !");
//    slideWidget2layout->addWidget(b22);

//    QPushButton *b31=new QPushButton("Isn't");
//    slideWidget3layout->addWidget(b31);
//    QPushButton *b32=new QPushButton("Qt cool ?");
//    slideWidget3layout->addWidget(b32);

//    QPushButton *b41=new QPushButton("How cool");
//    slideWidget4layout->addWidget(b41);
//    QPushButton *b42=new QPushButton("is Qt !");
//    slideWidget4layout->addWidget(b42);


//}

//void MainWindow::CreateConnections()
//{
//    QObject::connect(buttonNext,SIGNAL(pressed()),slidingStacked,SLOT(slideInNext()));
//    QObject::connect(buttonPrev,SIGNAL(pressed()),slidingStacked,SLOT(slideInPrev()));
//    QObject::connect(checkWrap,SIGNAL(clicked(bool)),slidingStacked,SLOT(setWrap(bool)));
//    QObject::connect(checkVertical,SIGNAL(clicked(bool)),slidingStacked,SLOT(setVerticalMode(bool)));
//    QObject::connect(slideSpeed,SIGNAL(valueChanged(int)),slidingStacked,SLOT(setSpeed(int)));
//    QObject::connect(slideSpeed,SIGNAL(valueChanged(int)),speedDisplay,SLOT(display(int)));
//    QObject::connect(listAll,SIGNAL(currentIndexChanged(int)),slidingStacked,SLOT(slideInIdx(int)));
//}

//void MainWindow::CreateSlidingStackedWidget()
//{
//    slidingStacked= new SlidingStackedWidget(this);
//    slidingStacked->addWidget(slideWidget1);
//    slidingStacked->addWidget(slideWidget2);
//    slidingStacked->addWidget(slideWidget3);
//    slidingStacked->addWidget(slideWidget4);
//    slidingStacked->setSpeed(animTime);


//}

MainWindow::~MainWindow()
{
    delete ui;

}

/*                          total 8 sec movement
 * |--------------------|-----------------------------------|
 * frame change(12s)    2sec move->3 sec paused-> 3sec move
 * duration of the movement is 8sec.
 * 5 sec movement, 3 sec paused.
 */
void MainWindow::move()
{

    auto animation = new QPropertyAnimation(gifmoving,"geometry");
    connect(animation,&QPropertyAnimation::finished,animation, &QPropertyAnimation::deleteLater);

    animation->setDuration(8000);
    //x set as 80
    animation->setStartValue(QRect(0,470,90,30));
    animation->setEasingCurve(QEasingCurve::Linear);
    //pause duaration(3s) divides by total duration(8s)
    animation->setKeyValueAt(0.375, QRect(460,470,90,30));
     //total duration minus pause duaration divides by total duration
    animation->setKeyValueAt(0.625, QRect(460,470,90,30));
    animation->setEndValue(QRect(920,470,90,30));
    animation->start();

}

void MainWindow::Opacity()
{

    opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(1.0);
    //time_for_next->setGraphicsEffect(opacityEffect);
    QPropertyAnimation* anim = new QPropertyAnimation(this);
    anim->setTargetObject(opacityEffect);
    anim->setPropertyName("opacity");
    anim->setDuration(500);
    anim->setStartValue(opacityEffect->opacity());
    //anim->setEndValue(end_value);
    anim->setEasingCurve(QEasingCurve::OutQuad);
    anim->start(QAbstractAnimation::DeleteWhenStopped);


}

void MainWindow::pictureRotate()
{
    QPushButton* btn = new QPushButton(this);
    QPushButton* btnAdd = new QPushButton(this);
    btn->setText(QString::number(buttonList.size()));
    btn->setGeometry(btnAdd->geometry());
    btn->show();

    buttonList.append(btn);

    rearrangeButtons();


}

void MainWindow::nextSlide1()
{
    stackedLayout->setCurrentIndex((stackedLayout->currentIndex()+1));

}

void MainWindow::LabelPaused()
{
    page2_label2->setText("1 mins");

}

void MainWindow::LabelMoving()
{
    page2_label1->setText("Train");
    page2_label2->setText("Arriving");
}

void MainWindow::LabelEnd()
{
    page2_label1->setText("       ");
    page2_label2->setText(" Train Arrived ");

}

void MainWindow::fadeInWidget(int)
{
    if (faderWidget)
        faderWidget->close();
    faderWidget = new FaderWidget(pagesWidget->widget(index));
    faderWidget->start();
}

void MainWindow::showTime1()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if (time.second() % 2 == 0)
    {
        time_text[3]= ' ';
        time_text[8]= ' ';
    }
    myTime1->setText(time_text);

}

void MainWindow::showTime2()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if (time.second() % 2 == 0)
    {
        time_text[3]= ' ';
        time_text[8]= ' ';
    }
    myTime2->setText(time_text);
}

void MainWindow::rearrangeButtons()
{
    int buttonCount = buttonList.size();
    float angleUnit = 6.28 /buttonCount;

    for (int i =0; i<buttonCount; i ++){
        QPushButton* btn = buttonList.at(i);
        QPropertyAnimation* animation = new QPropertyAnimation(btn,"geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::OutElastic);
        animation->setEndValue(QRectF(cos(angleUnit * i) * scale + xShift, sin(angleUnit * i )* scale + yShift, buttonSize, buttonSize));
        animation->start(QAbstractAnimation::DeleteWhenStopped);

    }

}

