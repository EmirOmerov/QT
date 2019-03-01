#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include "mydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_window_triggered()
{
    mDialog = new MyDialog(this);
    mDialog->show();

}
