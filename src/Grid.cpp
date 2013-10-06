#include "Grid.h"
  
Grid::Grid(int size) 
{
    this->grid = new int[size];
    gridSize = size;
}
Grid::Grid() 
{
    int size = 100;
    this->grid = new int[size];
    gridSize = size;
}
Grid::~Grid() 
{
    delete [] grid;
}
int* Grid::get_grid() 
{
    return this->grid;
}
int Grid::get_size() 
{
    return gridSize;
}
void Grid::set_grid(int i, int value) 
{
    this->grid[i] = value;
}
