#include "bullet.h"
#include "enemy.h"
#include <typeinfo>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "game.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/images/images/bullet1.png"));
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items [i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y()+50<0){
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Metak izbrisan";
    }

}

