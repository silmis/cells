#include "ImageMaker.h"
#include "Grid.h"

#include <opencv/cxcore.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

ImageMaker::ImageMaker(lifetime *lt)
{   
    m_lt = lt;
    m_gridXLen = lt->front()->get_size();
    m_gridYLen = lt->size(); 
}
ImageMaker::~ImageMaker()
{
    delete m_lt;
}
void ImageMaker::make_img()
{
    cv::Mat image = cv::Mat(m_gridYLen, m_gridXLen, CV_8UC3);
    for (int y=0; y<m_gridYLen; y++)
    {
        for (int x=0; x<m_gridXLen; x++)
        {
            if (m_lt->at(y)->get_grid()[x] == 1)
            {            
                image.at<cv::Vec3b>(y,x).val[0] = 255; 
                image.at<cv::Vec3b>(y,x).val[1] = 255; 
                image.at<cv::Vec3b>(y,x).val[2] = 255; 
            }
        }
    }

    //cv::putText(image, "Hello world", cvPoint(320, 200), 
    //    CV_FONT_HERSHEY_SIMPLEX, 1, cvScalar(255, 0, 0));
    cv::imwrite("/home/thitkone/Projects/play/cells/build/src/output.png", image);
}

