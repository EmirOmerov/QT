#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>


Player::Player():QObject(),QGraphicsPixmapItem()
{
    bulletsound=new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Bullet.wav"));
    //nacrtaj igraca
    setPixmap(QPixmap(":/images/images/player4.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        setPos(x()-10,y());
    }else if(event->key()==Qt::Key_Right){
        setPos(x()+10,y());
//   }else if(event->key()==Qt::Key_Up){
//        setPos(x(),y()-10);
//    }else if(event->key()==Qt::Key_Down){
//        setPos(x(),y()+10);
    }else if(event->key()==Qt::Key_Space){

        Bullet *bullet=new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        //pusti zvuk metka
        if(bulletsound->state()==QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }else if(bulletsound->state()==QMediaPlayer::StoppedState){
            bulletsound->play();
        }



    }


}

void Player::spawn()
{
    Enemy *enemy=new Enemy();
    scene()->addItem(enemy);
}

