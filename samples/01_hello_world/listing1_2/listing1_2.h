#ifndef LISTING1_2_H
#define LISTING1_2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class listing1_2; }
QT_END_NAMESPACE

class listing1_2 : public QMainWindow
{
    Q_OBJECT

public:
    listing1_2(QWidget *parent = nullptr);
    ~listing1_2();

private:
    Ui::listing1_2 *ui;
};
#endif // LISTING1_2_H
