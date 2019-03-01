#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_C, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_division, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_equals, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_minus, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_mnozenje, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_pim,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_plus, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_procenat, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_tacka, SIGNAL(released()),this,SLOT(digit_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed()
{
   QPushButton *button=(QPushButton*)sender();
   double labelNumber;
   QString newlabel;

   labelNumber=(ui->label->text() + button->text()).toDouble();
   newlabel = QString::number(labelNumber,'g',15);
   ui->label->setText(newlabel);


}
