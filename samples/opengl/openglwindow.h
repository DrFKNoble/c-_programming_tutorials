#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class OpenGLWindow; }
QT_END_NAMESPACE

class OpenGLWindow : public QMainWindow
{
    Q_OBJECT

public:
    OpenGLWindow(QWidget *parent = nullptr);
    ~OpenGLWindow();

private:
    Ui::OpenGLWindow *ui;
};
#endif // OPENGLWINDOW_H
