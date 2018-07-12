#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMenuBar>
#include "subwidget.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void change();
    void changeWindow();
    void returnWindow();

private:
    Ui::Widget *ui;

    QPushButton button1;
    QPushButton *button2;

    Subwidget swindow;
};

#endif // WIDGET_H
