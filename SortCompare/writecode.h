#ifndef WRITECODE_H
#define WRITECODE_H

#include <QWidget>

namespace Ui {
class WriteCode;
}

class WriteCode : public QWidget
{
    Q_OBJECT

public:
    explicit WriteCode(QWidget *parent = nullptr);
    ~WriteCode();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WriteCode *ui;
};

#endif // WRITECODE_H
