#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // my menu

    myMenuBar = new QMenuBar();

    fileMenu = myMenuBar->addMenu("File");

    fileExit = new QAction("Exit");

    fileMenu->addAction(fileExit);

    setMenuBar(myMenuBar);

    // my status bar

    myStatusBar = new QStatusBar();

    setStatusBar(myStatusBar);

    // my central widget

    myCentralWidget = new QWidget();

    // layouts

    vBoxLayout = new QVBoxLayout();

    // widgets

    textEdit = new QTextEdit();
    textEdit->setText("Hello World!");

    // add widgets to layout and assign to central widget

    vBoxLayout->addWidget(textEdit);

    myCentralWidget->setLayout(vBoxLayout);

    setCentralWidget(myCentralWidget);

    // signals and slots

    connect(fileExit, &QAction::triggered, this, &MainWindow::exit);

    // set window size

    setFixedSize(QSize(320, 240));
    setWindowTitle(QString("listing_01"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit()
{
    QApplication::exit();

    return;
}
