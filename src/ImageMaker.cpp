#include "ImageMaker.h"
#include "common.h"
//#include "Grid.h"

#include <opencv/cxcore.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

ImageMaker::ImageMaker()
{
}
ImageMaker::~ImageMaker()
{
}
void ImageMaker::make_img()
{
    cv::Mat image(480, 640, CV_8UC3);
    cv::putText(image, "Hello world", cvPoint(320, 200), 
        CV_FONT_HERSHEY_SIMPLEX, 1, cvScalar(255, 0, 0));
    cv::imwrite("/home/thitkone/Projects/play/cells/build/src/output.tif", image);
    //cv::namedWindow("ble", CV_WINDOW_AUTOSIZE);
    //cv::imshow("ble", image);
}

