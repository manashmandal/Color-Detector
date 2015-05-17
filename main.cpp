#include "colordetectcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ColorDetectController w;
    w.setWindowTitle("Phukin' Color Detector");
    w.show();

    return a.exec();
}
