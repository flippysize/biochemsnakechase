#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QLayout>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*
     * @brief creates a window
     * @param parent set as null pointer
     */
    MainWindow(QWidget *parent = nullptr);
    /*
     * @brief destructor
     */
    ~MainWindow();
    bool playing;
    QMediaPlayer* music;
private:
    Ui::MainWindow *ui;
    QLabel* welcome,  *author;  //welcome to game and authors displayed
    QLabel *picture;  //picture on welcome window
    QHBoxLayout* screenLayout; //screen layout to organize menu
    QVBoxLayout* VscreenLayout;
    QVBoxLayout* V2screenLayout;
    QWidget* menu; //menu
    QPushButton* start, *quit, *rules, *mute; //start aand quit buttons

 public slots:
    void  mute_music(QMediaPlayer* musical);
};
#endif // MAINWINDOW_H
