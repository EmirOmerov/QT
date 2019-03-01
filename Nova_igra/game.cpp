#include "game.h"
#include "enemy.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
{
    QGraphicsScene *scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":images/images/background3.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //igrac
    Player *player=new Player();
    player->setPos(350,500);
    //player->setRect(0,0,100,100);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //player->setPos(this->width()/2,this->height()-player->rect().height());

    scene->addItem(player);

    //stvaranje rezultata
    score=new Score();
    scene->addItem(score);

    //stvaranje zdravlja
    health=new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //pravimo neprijatelje
    QTimer *timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //pustanje pozadinske muzike
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bensound-dubstep.mp3"));
    music->play();


    show();

}

