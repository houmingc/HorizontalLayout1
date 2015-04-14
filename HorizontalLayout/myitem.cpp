#include "myitem.h"

myItem::myItem()
{
    //random start rotation
    angle = (90);
    setRotation(angle);

    //set the speed
    speed = 2;
    myItem::setPos(-200.0,0.0);

}

QRectF myItem::boundingRect() const
{
     return QRect(0,0,20,80);
}

void myItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     QRectF rec = boundingRect();
     QBrush Brush(Qt::red);

     painter->fillRect(rec,Brush);
     painter->drawRect(rec);

}

void myItem::advance(int phase)
{

    if(!phase)  return;
    QPointF location = this->pos();
    setPos(mapToParent(0,-(speed)));


}


myItem::~myItem()
{

}

