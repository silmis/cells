#include "Simulator.h"
#include "Grid.h"
#include "Ruleset.h"
#include "math.h"


Simulator::Simulator(Ruleset *ruleset, Grid *inputGrid, int iterations)
{
    m_ruleset = ruleset;
    m_inputGrid = inputGrid;
    m_iterations = iterations;
    m_result = new lifetime;
}
Simulator::~Simulator()
{
    delete m_ruleset;
    delete m_inputGrid;
    delete m_result;
}
string Simulator::toroid_left_side(int index, int overlap, int gridSize, string key) {
    int spill = overlap-index;
    for (int i=gridSize-spill; i<gridSize; i++)
    {   
        key += std::to_string(m_result->back()->get_grid()[i]);
    }
    for (int i=0; i<=index+overlap; i++ )
    {
        key += std::to_string(m_result->back()->get_grid()[i]);
    }
    return key;
}
string Simulator::toroid_right_side(int index, int overlap, int gridSize, string key) {
    int spill = (index+overlap)-(gridSize-1);
    for (int i=index-overlap; i<gridSize; i++) 
    { 
        key += std::to_string(m_result->back()->get_grid()[i]);
    }
    for (int i=0; i<spill; i++) {
        key += std::to_string(m_result->back()->get_grid()[i]);
    }
    return key;    
}
string Simulator::get_neighbourhood(int index, Grid *grid) 
{
    string key = "";
    int nbhSize = m_ruleset->get_neighbourhoodSize(); 
    int overlap = (int)floor(nbhSize / 2.0);
    int gridSize = grid->get_size();
    if (index<overlap) 
    {
        key = toroid_left_side(index, overlap, gridSize, key);
    } 
    else if (index>=(grid->get_size()-overlap))
    {
        key = toroid_right_side(index, overlap, gridSize, key);
    }
    else
    {
        for (int i=index-overlap; i<=index+overlap; i++)
        {
            key += std::to_string(m_result->back()->get_grid()[i]);
        }
    }
    return key;
}
void Simulator::run_simulation()
{
    Grid *nextIteration = m_inputGrid;
    rulemap *rules = m_ruleset->get_rules();
    for ( int i=0; i<m_iterations; i++ )
    {   
        gridPointer gptr(nextIteration);
        m_result->push_back(std::move(gptr));
        nextIteration = new Grid(m_inputGrid->get_size());
        for ( int k=0; k<m_inputGrid->get_size(); k++ )
        {
            string key = get_neighbourhood(k, nextIteration);
            string value = (*rules)[key];
            nextIteration->set_grid(k, std::stoi(value));
            std::cout << value;
        }
        std::cout << std::endl;
    }
}
