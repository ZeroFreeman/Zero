#include <QApplication>
#include <QWidget>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("你哈皮");


    QPushButton button(&window);
    button.setText("^0^");

    window.show();

    app.exec();
    return 0;
}
