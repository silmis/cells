#include "Grid.h"

Grid::Grid() 
{
    m_grid = new int[100];
    m_gridSize = 100;
    fill_empty();
}
Grid::Grid(int size) 
{
    m_grid = new int[size];
    m_gridSize = size;
    fill_empty();
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
void Grid::fill_empty()
{
    for (int i=0; i<m_gridSize; i++)
    {
        m_grid[i] = 0;
    }
}
void Grid::print() 
{
    for (int i=0; i<m_gridSize; i++)
    {
        std::cout << m_grid[i] << " ";
    }
}
