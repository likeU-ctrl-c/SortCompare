#ifndef SHOWALLSORT_H
#define SHOWALLSORT_H

#include <QWidget>
#include"sortshow.h"

namespace Ui {
class ShowAllSort;
}

class ShowAllSort : public QWidget
{
    Q_OBJECT

public:
    explicit ShowAllSort(QWidget *parent = nullptr);
    ~ShowAllSort();
    SortShow *s;

private:
    Ui::ShowAllSort *ui;
};

#endif // SHOWALLSORT_H
