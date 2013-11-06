#include "ImageMaker.h"
#include "Grid.h"
#include "Simulator.h"
#include "Ruleset.h"

#include <opencv/cxcore.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

ImageMaker::ImageMaker(Simulator *sim)
{
    m_sim = sim;  
    m_lt = sim->get_result();
    m_gridXLen = m_lt->front()->get_size();
    m_gridYLen = m_lt->size(); 
}
ImageMaker::~ImageMaker()
{   
    delete m_sim;
    delete m_lt;
}
void ImageMaker::make_img(string outPath)
{
    cv::Mat image = cv::Mat(m_gridYLen, m_gridXLen, CV_8UC3);
    for (unsigned int y=0; y<m_gridYLen; y++)
    {
        for (unsigned int x=0; x<m_gridXLen; x++)
        {
            if (m_lt->at(y)->get_grid()[x] == 1)
            {            
                image.at<cv::Vec3b>(y,x).val[0] = 255; 
                image.at<cv::Vec3b>(y,x).val[1] = 255; 
                image.at<cv::Vec3b>(y,x).val[2] = 255; 
            }
        }
    }
    string rulename = m_sim->get_ruleset()->get_rule_name();
    //cv::imwrite("/home/thitkone/Projects/play/cells/build/src/"+rulename+".png", image);
    cv::imwrite(outPath+"/"+rulename+".png", image);
}

