#include "Grid.h"

Grid::Grid() 
{
    m_grid = new int[100];
    m_gridSize = 100;
}
Grid::Grid(int size) 
{
    m_grid = new int[size];
    m_gridSize = size;
}
Grid::Grid(const Grid& orig)
{
    m_grid = new int[orig.m_gridSize];
    m_gridSize = orig.m_gridSize;
    for (int i=0; i<m_gridSize; i++)
    {   
        m_grid[i] = orig.m_grid[i];
    }
}
Grid::~Grid() 
{
    delete [] m_grid;
}
Grid& Grid::operator=(const Grid& orig)
{
    Grid temp (orig);
    std::swap(m_grid, temp.m_grid);
    std::swap(m_gridSize, temp.m_gridSize);
    return *this;
}
int* Grid::get_grid() 
{
    return m_grid;
}
int Grid::get_size() 
{
    return m_gridSize;
}
void Grid::set_grid(int i, int value) 
{
    m_grid[i] = value;
}
