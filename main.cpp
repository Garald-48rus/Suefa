#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>
#include <QPropertyAnimation>
#include <QHBoxLayout>
#include "suefa.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Suefa s;
    s.show();

   /* QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "suefa_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }


    QWidget wgt;

    QLabel* lbl1 = new QLabel{"Animated Window1"};
    QLabel* lbl2 = new QLabel{"Animated Window2"};
    QPropertyAnimation* panim1 =
        new QPropertyAnimation{lbl1, "geometry"};
    panim1->setDuration(3000);
    panim1->setStartValue(QRect{120, 0, 100, 100});
    panim1->setEndValue(QRect{400, 140, 200, 200});
    panim1->setEasingCurve(QEasingCurve::InOutExpo);
    panim1->start();

    QPropertyAnimation* panim2 =
        new QPropertyAnimation(lbl2, "pos");
    panim2->setDuration(3000);
    panim2->setStartValue(QPoint{300, -150});
    panim2->setEndValue(QPoint{50, -50});
    panim2->setEasingCurve(QEasingCurve::OutBounce);
    panim2->start();

    /*QParallelAnimationGroup group;
    group.addAnimation(panim1);
    group.addAnimation(panim2);
    group.setLoopCount(3);
    group.start();




    QHBoxLayout* hbl = new QHBoxLayout;
    hbl->addWidget(lbl1);
    hbl->addWidget(lbl2);

    wgt.setLayout(hbl);
    wgt.resize(600,600);
    wgt.show();
    */
    return a.exec();
}
