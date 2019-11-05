#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    screenLayout = new QHBoxLayout;
    VscreenLayout = new QVBoxLayout;
    V2screenLayout = new QVBoxLayout;
    //QHBoxLayout* temp = new QHBoxLayout;
    //QHBoxLayout* temp2 = new QHBoxLayout;
    setFixedSize(1000,900);
    // text on screen
    welcome = new QLabel("Welcome to Biochem Snake!",this);
    //temp->addWidget(welcome);
    //welcome-> setGeometry(0,0, 1000, 400);
    //VscreenLayout->addWidget(welcome);
    welcome->setAlignment(Qt::AlignCenter);
    welcome ->setStyleSheet("QLabel {font: 35pt; color: green;}");
    author = new QLabel("Created by Chase DeLong, Jonathan King, and Oscar Molina", this);
    //author-> setGeometry(0,0,1000,600);
    //VscreenLayout->addWidget(author);
    author-> setAlignment (Qt::AlignCenter);
    author ->setStyleSheet("QLabel {font: 12pt; color: green;}");
    //temp2->addWidget(author);
    //buttons in menw
    start = new QPushButton("Start");
    start->setFixedSize(200,50);
    start->setStyleSheet("QPushButton {font: 20pt; color: white; background-color:black}");
    quit = new QPushButton("Quit");
    rules = new QPushButton("Rules");
    rules->setFixedSize(200,50);
    rules->setStyleSheet("QPushButton {font: 20pt; color: white; background-color:black}");
    quit->setFixedSize(200,50);
    quit->setStyleSheet("QPushButton {font: 20pt; color: white; background-color:black}");
    mute = new QPushButton("Mute");
    mute->setFixedSize(200,50);
    mute->setStyleSheet("QPushButton {font: 20pt; color: white; background-color:black}");
    //makes quit button quit
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    menu = new QWidget();
    // make menu be central widget
    //QWidget* tester = new QPushButton("tester");
    //tester->setFixedSize(200,50);
    //tester->setStyleSheet("QPushButton {font: 20pt; color: white; background-color:black}");
    //VscreenLayout->setMargin(0);
    //VscreenLayout->setSpacing(0);
    QVBoxLayout* overall_v = new QVBoxLayout;
    overall_v->addWidget(welcome);
    overall_v->addWidget(author);
    //VscreenLayout->addLayout(temp);
    //VscreenLayout->addLayout(temp2);
    VscreenLayout->addWidget(start);
    VscreenLayout->addWidget(mute);
    V2screenLayout->addWidget(rules);
    V2screenLayout->addWidget(quit);
    //V2screenLayout->setMargin(0);
    //V2screenLayout->setSpacing(0);
    screenLayout->addLayout(VscreenLayout);
    screenLayout->addLayout(V2screenLayout);
    overall_v->addLayout(screenLayout);
    //screenLayout->setMargin(0);
    //screenLayout->setSpacing(0);
    //screenLayout->addWidget(tester);

    //screenLayout->addWidget(start);
    //screenLayout->addWidget(rules);
    //screenLayout->addWidget(quit);

    //picture in title screen
    picture = new QLabel (this);

    //picture->setGeometry(200,500,600,400);
    QPixmap pic (":/essential-amino-acids-chart-abbreviations-and-structure-324357-1.jpg");
    //picture->setPixmap(pic);
    picture->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    //QHBoxLayout* for_pic = new QHBoxLayout;
    //for_pic->addWidget(picture);
    //overall_v->addWidget(picture);

    QWidget* instructions_window = new QWidget;

    //QLabel* inst_background = new QLabel(this);

    //inst_background->setPixmap(inst_bac);
    //inst_background->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    //overall_v->setAlignment(Qt::AlignCenter);
    //QLayout::setAlignment(picture, Qt::AlignCenter);
    QVBoxLayout* rules_lay = new QVBoxLayout;
    //rules_lay->addWidget(inst_background);
    instructions_window->setLayout(rules_lay);
    QLabel* rule_main = new QLabel("GAME RULES");
    QLabel* rule_1 = new QLabel("1. Every normal (white) pellet will increase your length by 1 and increase your score by 100 points.");
    QLabel* rule_2 = new QLabel("2. When you come in contact with a colored square, a question of corresponding difficulty will be initiated.");
    QLabel* rule_3 = new QLabel("3. Answering the question right/wrong will result in blocks being removed/added to your snake.");
    rules_lay->addWidget(rule_main);
    rules_lay->addWidget(rule_1);
    rules_lay->addWidget(rule_2);
    rules_lay->addWidget(rule_3);
    connect(rules, SIGNAL(clicked()), instructions_window, SLOT(show()));

    //instructions_window->setStyleSheet("background-image: url(:/379457.jpg)");
    instructions_window->resize(1000,900);
    menu->setLayout(overall_v);
    //QPixmap inst_bac2 (":/379457.jpg");
    //inst_bac2 = inst_bac2.scaled(menu->size(), Qt::KeepAspectRatioByExpanding);
    //QPalette palette2;
    //palette2.setBrush(QPalette::Background, inst_bac2);
    //this->setPalette(palette2);
    this->setCentralWidget(menu);
    QPixmap inst_bac (":/pattern_back.jpg");
    inst_bac = inst_bac.scaled(instructions_window->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, inst_bac);
    this->setPalette(palette);
    music = new QMediaPlayer();
    music->setMedia (QUrl("qrc:/Bill_Nye_Song.mp3"));
    music->play();
    playing = true;
    connect(mute, SIGNAL(clicked()), music, SLOT(mute_music(music)));
}

MainWindow::~MainWindow()
{
}

