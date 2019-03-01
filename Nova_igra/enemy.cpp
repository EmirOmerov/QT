#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "game.h"
extern Game *game;
Enemy::Enemy(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    int random_number=rand()%700;
    setPos(random_number, 0);
    //setRect(0,0,100,100);
      setPixmap(QPixmap(":/images/images/enemy.png"));
    //ako su pogresno okrenuti
      setTransformOriginPoint(50,50);
      setRotation(180);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y()+30>600){
        game->health->decrease();
        qDebug() << "Neprijatelj izbrisan";
        scene()->removeItem(this);
        delete this;
    }

}

