#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class Subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Subwidget(QWidget *parent = 0);
    void sendSignal();

signals:
    void mySignal();


public slots:


private:
    QPushButton sbutton1;

};

#endif // SUBWIDGET_H
