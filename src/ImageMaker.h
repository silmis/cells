#ifndef __IMAGEMAKER_H_INCLUDED__
#define __IMAGEMAKER_H_INCLUDED__

#include "common.h"

class ImageMaker
{ 
    private:
        lifetime * m_lt;
        unsigned int m_gridXLen;
        unsigned int m_gridYLen;
    public:
        ImageMaker(lifetime *lt);
        ~ImageMaker();
        void make_img();
};

#endif
