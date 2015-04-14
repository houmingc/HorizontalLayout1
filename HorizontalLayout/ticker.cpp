#include "ticker.h"
#include <QtGui>
#include <QMainWindow>

extern QLabel *label;

Ticker::Ticker(QWidget *parent) : QWidget(parent),offset_(0),timerId_(0)
{}

Ticker::~Ticker()
{

}

void Ticker::setText(const QString& text) // 2
{
  text_ = text;
  update();
  updateGeometry();
}

void Ticker::paintEvent(QPaintEvent*) // 3
{
          QPainter painter(this);

          int textWidth = fontMetrics().width(text_);
          if (textWidth < 1)
            return;
          int x = -offset_;
          while (x < width())
          {
            painter.drawText(x, 0, textWidth, height(), Qt::AlignLeft | Qt::AlignVCenter, text_);
            x += textWidth;
          }
}

void Ticker::showEvent(QShowEvent *) // 4
{
            timerId_ = startTimer(30);
}

void Ticker::timerEvent(QTimerEvent *event) // 5
{
          if(event->timerId() == timerId_)
          {
            ++offset_;
            if(offset_ >= fontMetrics().width(text_))
              offset_ = 0;
            update();
          }
          else
            QWidget::timerEvent(event);
}

void Ticker::hideEvent(QHideEvent*) // 6
{
          killTimer(timerId_);
          timerId_ = 0;
}
