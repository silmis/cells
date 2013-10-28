#ifndef __GRID_H_INCLUDED__
#define __GRID_H_INCLUDED__

#include <iostream>
#include <vector>

class Grid {
    private:
        int *m_grid;
        int m_gridSize;
        void fill_empty();
        void fill_random(int states);
    public:
        Grid();
        Grid(int size);
        Grid(int size, const std::string option);
        Grid(const Grid& orig);
        ~Grid();
        Grid& operator=(const Grid& orig);        
        int* get_grid() { return m_grid; };
        void set_grid(int i, int value) { m_grid[i] = value; };
        int get_size() { return m_gridSize; };
        void print();
};

#endif
