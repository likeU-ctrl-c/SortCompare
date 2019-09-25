#include "showallsort.h"
#include "ui_showallsort.h"

ShowAllSort::ShowAllSort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowAllSort)


}

ShowAllSort::~ShowAllSort()
{
    delete ui;
}
