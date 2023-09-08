#ifndef SUEFA_H
#define SUEFA_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QObject>

class Suefa : public QWidget
{
    Q_OBJECT
public:
    explicit Suefa(QWidget *parent = nullptr);


private:
    QPushButton* stone;
    QPushButton* scissors;
    QPushButton* paper;
    QPushButton* ext;
    QLabel* player ;
    QLabel* comp;
    QLabel* total;
    QLabel* total2;
    QPixmap image{};
    QVector<QString> vec{"/home/garald/Qt Programm/suefa/stone.png",
                         "/home/garald/Qt Programm/suefa/scissors.png",
                         "/home/garald/Qt Programm/suefa/paper.png"};
    int p{0}, c{0}, tmp_p{};

public slots:
    void ClickedStone();
    void ClickedScissors();
    void ClickedPaper();
    void exit();
private:
    void game(QPixmap &);

};

#endif // SUEFA_H
