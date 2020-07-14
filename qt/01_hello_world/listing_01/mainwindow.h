#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void exit();

private:
    Ui::MainWindow *ui;

    // my menu

    QMenuBar *myMenuBar;

    QMenu *fileMenu;

    QAction *fileExit;

    // my status bar

    QStatusBar *myStatusBar;

    // my central widget

    QWidget *myCentralWidget;

    // layouts

    QVBoxLayout *vBoxLayout;

    // widgets

    QTextEdit *textEdit;

};
#endif // MAINWINDOW_H
