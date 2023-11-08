#include "mainwindow.h"
#include "mainwidget.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MainWidget *main = new MainWidget(this);
    setCentralWidget(main);
}

MainWindow::~MainWindow()
{
}

