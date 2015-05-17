#include "colordetectcontroller.h"
#include "ui_colordetectcontroller.h"
#include <QFileDialog>
#include <QMessageBox>


ColorDetectController::ColorDetectController(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorDetectController)
{
    ui->setupUi(this);
    cdetect = new ColorDetector();
}


void ColorDetectController::setColorDistanceThreshold(int distance){
    cdetect->setColorDistanceThreshold(distance);
}

int ColorDetectController::getColorDistanceThreshold() const {
    return cdetect->getColorDistanceThreshold();
}

void ColorDetectController::setTargetColor(unsigned char red, unsigned char green, unsigned char blue){
    cdetect->setTargetColor(red, green, blue);
}

void ColorDetectController::getTargetColor(unsigned char &red, unsigned char &green, unsigned char &blue) const
{
    cv::Vec3b color = cdetect->getTargetColor();
    red = color[2];
    green = color[1];
    blue = color[0];

}

bool ColorDetectController::setInputImage(std::string fileName)
{
    image = cv::imread(fileName);
    if (!image.data) return false;
    else return true;
}

const cv::Mat ColorDetectController::getInputImage() const {
    return image;
}

void ColorDetectController::process(){
    result = cdetect->process(image);
}

const cv::Mat ColorDetectController::getLastResult() const
{
    return result;
}


ColorDetectController::~ColorDetectController()
{
    delete ui;
}

void ColorDetectController::on_openImage_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open Image", ".", "Image Files (*.png *.jpg *.jpeg *.bmp");

    if (file_name == NULL){
        QMessageBox::information(this, "Why man Why??..", "Please choose an image to get output");
    }

    else {
        image = cv::imread(file_name.toLatin1().data());
        this->setInputImage(file_name.toLatin1().data());
        cv::imshow("Input Image", this->getInputImage());
    }

}

void ColorDetectController::on_processButton_clicked()
{
    this->setTargetColor(130, 190, 230);
    this->process();
    cv::imshow("Output Result", this->getLastResult());
}

void ColorDetectController::on_OKAbutton_clicked()
{
    this->close();
}
