#include "food.h"
#include <QBrush>


food::food(QGraphicsItem *parent,QString name):QGraphicsPixmapItem(parent)
{
    if(name == "APPLE"){
        setPixmap(QPixmap(":/images/images/food.png").scaled(40,40));
        score = 5;
    }
    else{
        setPixmap(QPixmap(":/images/images/food2.jpg").scaled(40,40,Qt::KeepAspectRatio));
        score = 10;
    }
}
