#ifndef __IMAGEMAKER_H_INCLUDED__
#define __IMAGEMAKER_H_INCLUDED__

#include "common.h"
class Simulator;

class ImageMaker
{ 
    private:
        Simulator * m_sim;
        lifetime * m_lt;
        unsigned int m_gridXLen;
        unsigned int m_gridYLen;
    public:
        ImageMaker(Simulator *sim);
        ~ImageMaker();
        void make_img();
};

#endif
