#ifndef TICKER_H
#define TICKER_H

#include <QWidget>
#include "mainwindow.h"

class Ticker : public QWidget
{
    Q_OBJECT
public:
    explicit Ticker(QWidget *parent = 0);
    void setText(const QString& text);
    QString text() const {return text_;}

protected:
  void paintEvent(QPaintEvent*);
  void timerEvent(QTimerEvent* event);
  void showEvent(QShowEvent*);
  void hideEvent(QHideEvent*);
    ~Ticker();

signals:

public slots:

private:
  QString text_;
  int offset_;
  int timerId_;

};

#endif // TICKER_H
