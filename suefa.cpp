#include "suefa.h"
#include <QHBoxLayout>
#include <QRect>
#include <QPropertyAnimation>
#include <QApplication>



Suefa::Suefa(QWidget *parent)
    : QWidget{parent}, stone{new QPushButton{"Камень"}},
    scissors{new QPushButton{"Ножницы"}},
    paper{new QPushButton{"Бумага"}}, ext{new QPushButton{"Выход"}},
    player{new QLabel{}}, comp{new QLabel{}}, total{new QLabel{}},
    total2{new QLabel{}}
{
    this->setWindowTitle("Камень, Ножницы, Бумага");
    stone->setStyleSheet("color: white; background-color: black;");
    scissors->setStyleSheet("color: white; background-color: blue;");
    paper->setStyleSheet("color: white; background-color: green;");
    ext->setStyleSheet("color: white; background-color: red;");

     QObject::connect(stone, SIGNAL(clicked()), this, SLOT(ClickedStone()));
     QObject::connect(paper, SIGNAL(clicked()), this, SLOT(ClickedPaper()));
     QObject::connect(scissors, SIGNAL(clicked()), this, SLOT(ClickedScissors()));


    QObject::connect(ext, SIGNAL(clicked()), this, SLOT(exit()));
    setFixedSize(600, 600);
    player->setFixedSize(200, 200);
    comp->setFixedSize(200, 200);

    total2->setFixedSize(50, 50);
    total2->setAlignment(Qt::AlignCenter);
    QFont font = total2->font();
    font.setPixelSize(24);
    total2->setFont(font);
    total2->setStyleSheet("font-weight: bold; color: red");
    total2->setNum(c);

    total->setFixedSize(50, 50);
    total->setAlignment(Qt::AlignCenter);
    font = total->font();
    font.setPixelSize(24);
    total->setFont(font);
    total->setStyleSheet("font-weight: bold; color: green");
    total->setNum(p);



    QHBoxLayout* phbl = new QHBoxLayout;
    phbl->addWidget(stone);
    phbl->addWidget(scissors);
    phbl->addWidget(paper);
    phbl->addWidget(ext);
    phbl->setAlignment(Qt::AlignmentFlag::AlignBottom);

    QHBoxLayout* phbl1 = new QHBoxLayout;
    phbl1->addWidget(player);
    phbl1->addWidget(comp);

    QHBoxLayout* phbl2 = new QHBoxLayout;
    phbl2->addWidget(total);
    phbl2->addWidget(total2);
    phbl2->setSpacing(220);
    phbl2->setAlignment(Qt::AlignBottom | Qt::AlignCenter);

    QBoxLayout* phb = new QVBoxLayout;
    phb->addLayout(phbl1);
    phb->addLayout(phbl2);
    phb->addLayout(phbl);

    this->setLayout(phb);


}
//===================================================================
void Suefa::ClickedStone()
{
    image.load("/home/garald/Qt Programm/suefa/stone.png");
    tmp_p = 0;

    game(image);
}
//===========================================
void Suefa::ClickedScissors()
{
    image.load("/home/garald/Qt Programm/suefa/scissors.png");
    tmp_p = 1;

    game(image);
}
//==================================
void Suefa::ClickedPaper()
{
    image.load("/home/garald/Qt Programm/suefa/paper.png");
    tmp_p = 2;

    game(image);
}
//===================================================================================
void Suefa::exit()
{
    QApplication::quit();
}
//=================================================
void Suefa::game(QPixmap & image)
{
    player->setPixmap(image);

    QPropertyAnimation* panim1 =
        new QPropertyAnimation(player, "pos");
    panim1->setDuration(3000);
    panim1->setStartValue(QPoint{70, -220});
    panim1->setEndValue(QPoint{70, 150});
    panim1->setEasingCurve(QEasingCurve::OutBounce);
    panim1->start();


    int tmp_c = 0 + rand() % (2 - 0);
    comp->setPixmap(QPixmap(vec.at(tmp_c)));
    QPropertyAnimation* panim2 =
        new QPropertyAnimation(comp, "pos");
    panim2->setDuration(5000);
    panim2->setStartValue(QPoint{330, -410});
    panim2->setEndValue(QPoint{330, 150});
    panim2->setEasingCurve(QEasingCurve::OutBounce);
    panim2->start();


   if (tmp_p == 0 && tmp_c == 1) {
        p++;
    }
   else if (tmp_p == 1 && tmp_c == 2) {
        p++;
   }
   else if (tmp_p == 2 && tmp_c == 0) {
        p++;
    }
   else if (tmp_c == tmp_p) {

   }
    else {
        c++;
    }

   total->setNum(p);
   total2->setNum(c);
}
//=======================================================================

