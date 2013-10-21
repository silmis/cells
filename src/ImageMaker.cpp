#include "ImageMaker.h"
#include "common.h"
//#include "Grid.h"

#include <opencv2/cxcore.h>
#include <opencv2/cv.h>
#include <opencv/highgui.h>

ImageMaker::ImageMaker()
{
    cv::Mat image(480, 640, CV_8UC3);
    cv::putText(image, "Hello world", cvPoint(320, 200), 
        CV_FONT_HERSHEY_SIMPLEX, 1, cvScalar(255, 0, 0));
    cv::imwrite("output.tif", image);
}
ImageMaker::~ImageMaker()
{
}
