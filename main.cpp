#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void MainWindow::mute_music(QMediaPlayer* musical) {
    if(playing) {
        musical->stop();
        playing = false;
    } else {
        musical->play();
        playing = true;}
}
