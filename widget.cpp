#include "widget.h"
#include "ui_widget.h"
#include "iostream"

QList<QString> all_left {"Male","Left","Silence","JEt","Flagman","QBox","ISAAK"};
QList<QString> all_right {"Sport","Basket","Junk","Proga","Plane","Afganistan","SpanchBob"};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    left =  new QListWidget;
    right = new QListWidget;
    sort1 = new QPushButton;
    sort2 = new QPushButton;
    move1 = new QPushButton;
    move2 = new QPushButton;
    sort1->setText("Sort column");
    sort2->setText("Sort column");
    move1->setText(">>");
    move2->setText("<<");
    QFont font;
    font.setPixelSize(16);
    font.setBold(1);
    move1->setFont(font);
    move2->setFont(font);
    sort1->setFont(font);
    sort2->setFont(font);
    LLeft = new QVBoxLayout;
    LRight = new QVBoxLayout;
    LCenter = new QVBoxLayout;
    LAlign = new QHBoxLayout;
    LAlign->addLayout(LLeft);
    LAlign->addLayout(LCenter);
    LAlign->addLayout(LRight);
    LLeft->addWidget(left);
    LRight->addWidget(right);
    LLeft->addWidget(sort1);
    LCenter->addWidget(move1);
    LCenter->addStretch();
    LRight->addWidget(sort2);
    LCenter->addWidget(move2);
    right->addItems(all_right);
    left->addItems(all_left);
    setLayout(LAlign);
    setMaximumSize(900,900);
    setMinimumSize(500,500);
    connect(sort1,SIGNAL(clicked()),this,SLOT(left_sort()));
    connect(sort2,SIGNAL(clicked()),this,SLOT(right_sort()));
    connect(move1,SIGNAL(clicked()),this,SLOT(moveRight()));
    connect(move2,SIGNAL(clicked()),this,SLOT(moveLeft()));
}

Widget::~Widget() {
    delete ui;
}

