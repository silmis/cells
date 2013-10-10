#ifndef __GRID_H_INCLUDED__
#define __GRID_H_INCLUDED__

#include <iostream>
#include <vector>

class Grid {
    private:
        int *m_grid;
        int m_gridSize;
    public:
        Grid();
        Grid(int size);
        Grid(const Grid& orig);
        ~Grid();
        Grid& operator=(const Grid& orig);        
        int* get_grid();
        void set_grid(int i, int value);
        int get_size();
};

#endif
