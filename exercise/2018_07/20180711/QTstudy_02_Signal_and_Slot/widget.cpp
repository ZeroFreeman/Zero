#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(400, 400);

    button1.setParent(this);
    button1.setText("切换到子窗口");
    button1.move(0, 350);


    button2 = new QPushButton(this);
    button2->setText("close");
    button2->move(100, 100);

    //swindow.show();

    connect(button2, &QPushButton::pressed, this, &Widget::close);
    connect(&button1, &QPushButton::pressed, this, &Widget::changeWindow);


    //connect(&swindow, &Subwidget::mySignal, this, &Widget::returnWindow);

    //Lambda表达式的方便用法  和上面的被注释掉的作用相同

    connect(&swindow, &Subwidget::mySignal,
            [=]() mutable
    {
        this->show();
        swindow.hide();
    }



    );

//    button2 : 信号发出者,一个指针(为信号发出处的地址)
//    &QPushButton::pressed ：进行一操作后会有多个信号发出，选择处理需要的信号  当前发送者的类名::选择处理的信号名字
//    this : 信号接受者，也是一个指针(接受信号的地址)
//    &Widget::close : 对特定的信号做出反应处理   当前接受者的类名::选择处理信号的槽函数的名字


}

void Widget::changeWindow()
{
    this->hide();
    swindow.show();

}

void Widget::returnWindow()
{
    this->show();
    swindow.hide();
}



void Widget::change()
{
    button2->setText("hahahahah");
    button1.move(100, 300);
}




Widget::~Widget()
{
    delete ui;
}
