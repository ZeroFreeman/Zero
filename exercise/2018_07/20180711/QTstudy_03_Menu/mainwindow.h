#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QDockWidget>
#include <QDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void linkSignal();

private:
    QMenuBar *mBar;
    QToolBar *tBar;
    QStatusBar *sBar;
    QTextEdit *edit_1, *edit_2;
    QDockWidget *dwin_1;
    QPushButton *button, myButtonYes, myButtonNo;

    QMenu *pFile, *pTools;
    QAction *pNew_build, *pOpen, *pmDialog, *pmlDialog, *about_Dialog, *question_Dialog, *file_Dialog, *my_dialog;
    QDialog mdlg, mydialog;
};

#endif // MAINWINDOW_H
