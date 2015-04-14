#ifndef MYITEM_H
#define MYITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>


class myItem : public QGraphicsItem
{
public:
    myItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    //fire on the scene, scene tell every object to advance
    void advance(int phase);
private:
    qreal angle;
    qreal speed;


    ~myItem();
};

#endif // MYITEM_H
