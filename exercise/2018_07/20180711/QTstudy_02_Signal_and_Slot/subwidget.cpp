#include "subwidget.h"
#include <QPushButton>

Subwidget::Subwidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("子窗口");
    this->resize(400, 400);

    sbutton1.setParent(this);
    sbutton1.setText("切换到主窗口");
    sbutton1.move(0, 350);

    connect(&sbutton1, &QPushButton::pressed, this, &Subwidget::sendSignal);
}

void Subwidget::sendSignal()
{
    emit mySignal();
}
