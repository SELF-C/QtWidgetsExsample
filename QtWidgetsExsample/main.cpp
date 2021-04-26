#include "QtWidgetsExsample.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsExsample w;
    w.setFixedSize(640, 480);
    w.setWindowTitle("Qt example");
    w.show();
    return a.exec();
}
