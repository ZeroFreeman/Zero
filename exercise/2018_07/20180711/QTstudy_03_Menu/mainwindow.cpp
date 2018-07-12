#include "mainwindow.h"
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//Set Surface  设定界面
    this->resize(800, 600);
    mBar = menuBar();
    setMenuBar(mBar);
    tBar = addToolBar("tool");
    sBar = statusBar();

//Set MeunBar 设定菜单栏
    pFile = mBar->addMenu("Menu");
    pTools = mBar->addMenu("Tools");

//Set StatusBar 设定状态栏
    sBar->addWidget(new QLabel("Normal File", this));
    sBar->addPermanentWidget(new QPushButton("Now", this));

//Set Action of Menu  设定菜单栏动作
    pNew_build = pFile->addAction("NewBuild");
    pOpen = pFile->addAction("Open");
    connect(pOpen, &QAction::triggered,
            [=]() mutable
    {
        qDebug() << "Hello World";
    });

    pFile->addSeparator();  //分割线

    //----------------------------------------------//
    //Set Model dialog box and Modeless dialog box  设定模态对话框和非模态对话框的两种写法
    pmDialog = pFile->addAction("model dialog box");
    connect(pmDialog, &QAction::triggered,
            [=]()
    {
        mdlg.exec();   //此方法用指针的话和下面方法基本无异，无法减少代码量，所以建议创建非指针变量QDialog mdlg
    });
    pmlDialog = pFile->addAction("modeless dialog box");    //多用此方法
    connect(pmlDialog, &QAction::triggered,
            [=]()
    {
        QDialog *dlg = new QDialog;
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show();

    });

    pFile->addSeparator();

    //----------------------------------------------//
    //Set Standard Dialog and File Dialog  设定标准对话框和文件对话框
    about_Dialog = pFile->addAction("about dialog");
    connect(about_Dialog, &QAction::triggered,
            [=]()
    {
        QMessageBox::about(this, "关于", "学习窗口1.0");

    });
    question_Dialog = pFile->addAction("question dialog");
    connect(question_Dialog, &QAction::triggered,
            [=]()
    {
        int ret = QMessageBox::question(this, "提示", "是否关闭", QMessageBox::Yes | QMessageBox::No);
        switch(ret)
        {
        case QMessageBox::Yes:
            close();    //关掉整个程序窗口
            break;
        default:
            break;
        }
    });
    file_Dialog = pFile->addAction("file dialog");  //打开文件
    connect(file_Dialog, &QAction::triggered,
            [=]()
    {
        QFileDialog::getOpenFileName(
                    this,
                    "打开文件",
                    "../",
                    "All File(*.*);;"
                    "Image(*.jpg *.png *.gif);;"
                    "Source(*.cpp *.h *.pro)");
    });

    pFile->addSeparator();

    //---------------------------------------------------------//
    //Set my Dialog  设定我自己的对话框  Error!未解决
    my_dialog = pFile->addAction("my dialog");
    connect(my_dialog, &QAction::triggered,
            [=]()
    {
        mydialog.resize(400, 350);
        mydialog.show();
        myButtonYes.setParent(&mydialog);
        myButtonYes.setText("Yes");
        myButtonYes.move(300, 300);
        myButtonNo.setParent(&mydialog);
        myButtonNo.setText("No");
        myButtonNo.move(250, 300);

    });


//Set Action of Tools  设定工具栏动作  工具栏动作即为菜单里动作的快捷方式
    button = new QPushButton(this);
    button->setText("^0^");

    tBar->addWidget(button);
    tBar->addAction(pNew_build);

//Set Central Widget 设定核心控件
    edit_1 = new QTextEdit(this);
    this->setCentralWidget(edit_1);

//Set Dock Widget  设定浮动窗口
    dwin_1 = new QDockWidget(this);
    this->addDockWidget(Qt::RightDockWidgetArea, dwin_1);
    edit_2 = new QTextEdit(this);
    dwin_1->setWidget(edit_2);

}

MainWindow::~MainWindow()
{

}
