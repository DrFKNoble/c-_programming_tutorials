#ifndef LISTING1_1_H
#define LISTING1_1_H

#include <QMainWindow>

namespace Ui {
class listing1_1;
}

class listing1_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit listing1_1(QWidget *parent = nullptr);
    ~listing1_1();

private:
    Ui::listing1_1 *ui;
};

#endif // LISTING1_1_H
