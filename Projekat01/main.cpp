#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString tekst = "<h2><i>Pozdrav svijete<i/><font color=red>Qt!<font></h2>";
    QLabel * label = new QLabel(tekst);
    label->show();

    return app.exec();
}
