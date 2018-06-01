#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mbar = menuBar();
    QMenu *pFile = mbar->addMenu("file");
    QAction *pNew = pFile->addAction("new-build");

}

MainWindow::~MainWindow()
{

}
