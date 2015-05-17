#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>


class ColorDetector
{
private:

    //minimum acceptable distance
    int minDist;
    // target color
    cv::Vec3b target;

public:

    //image containing resulting binary map
    cv::Mat result;


    ColorDetector() : minDist(100){
        // Default parameter initialization here
        target[0] = target[1] = target[2] = 0;
    }

    void setColorDistanceThreshold(int distance);

    int getColorDistanceThreshold() const;

    //Sets the color to be detected

    void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);

    //Overloaded method [Color to be detected]
    void setTargetColor(cv::Vec3b color);

    cv::Vec3b getTargetColor() const;

    int getDistance(const cv::Vec3b& color) const;

    //Process definition
    cv::Mat process(const cv::Mat &image);

    ~ColorDetector();
};


#endif // COLORDETECTOR_H
