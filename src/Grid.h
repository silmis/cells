#ifndef __GRID_H_INCLUDED__
#define __GRID_H_INCLUDED__

class Grid {
    private:
        int *grid;
        int gridSize;
    public:
        Grid();
        Grid(int size);
        ~Grid();
        int* get_grid();
        void set_grid(int i, int value);
        int get_size();
};

#endif
