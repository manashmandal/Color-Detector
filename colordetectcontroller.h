#ifndef COLORDETECTCONTROLLER_H
#define COLORDETECTCONTROLLER_H

#include <QDialog>
#include "colordetector.h"
#include <QString>
#include <QtCore>

namespace Ui {
class ColorDetectController;
}

class ColorDetectController : public QDialog
{
    Q_OBJECT

private:
    ColorDetector *cdetect;


    cv::Mat image;
    cv::Mat result;



public:
    explicit ColorDetectController(QWidget *parent = 0);
    void setColorDistanceThreshold(int distance);
    int getColorDistanceThreshold() const;
    void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
    void getTargetColor(unsigned char &red, unsigned char &green, unsigned char &blue) const;
    bool setInputImage(std::string fileName);
    const cv::Mat getInputImage() const;
    void process();
    const cv::Mat getLastResult() const;


    ~ColorDetectController();

private slots:
    void on_openImage_clicked();

    void on_processButton_clicked();

    void on_OKAbutton_clicked();

private:
    Ui::ColorDetectController *ui;
};

#endif // COLORDETECTCONTROLLER_H
