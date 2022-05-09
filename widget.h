#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void left_sort(){
        left->sortItems();
    }

    void right_sort() {
       Qt::SortOrder order = Qt::DescendingOrder;
       right->sortItems(order);
    }

    void moveLeft() {
       left->addItem(right->takeItem(right->currentRow()));
       right->setCurrentRow(-1);
    }

    void moveRight() {
       right->addItem(left->takeItem(left->currentRow()));
       left->setCurrentRow(-1);
    }

    void Rremember() {
        right->selectedItems();
    }

private:
    Ui::Widget *ui;
    QListWidget *left;
    QListWidget *right;
    QPushButton *sort1;
    QPushButton *sort2;
    QPushButton *move1;
    QPushButton *move2;
    QVBoxLayout *LLeft;
    QVBoxLayout *LRight;
    QVBoxLayout *LCenter;
    QHBoxLayout *LAlign;
};
#endif
