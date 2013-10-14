#include "Simulator.h"
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
string Simulator::get_neighbourhood(int index, Grid *grid) 
{
    string key = "";
    int nbhSize = m_ruleset->get_neighbourhoodSize(); 
    int overlap = (int)floor(nbhSize / 2.0);
    if (index<overlap) 
    {
        std::cout << "at beginning " << index << " overlap " << overlap;
    } 
    else if (index>=(grid->get_size()-overlap))
    {    
        std::cout << "at beginning " << index << " overlap " << overlap;
    }
    else
    {
        for (int i=index-overlap; i<=index+overlap; i++)
        {
            key += grid->get_grid()[i];
        }
        std::cout << key << std::endl;
    }
    return key;
}
void Simulator::run_simulation()
{
    Grid *nextIteration = m_inputGrid;
    Grid *temp;
    for ( int i=0; i<m_iterations; i++ )
    {   
        temp = nextIteration;
        gridPointer gptr(temp);
        m_result->push_back(std::move(gptr));
        delete nextIteration;
        Grid *nextIteration = new Grid(m_inputGrid->get_size());
        for ( int k=0; k<m_inputGrid->get_size(); k++ )
        {
            string key = get_neighbourhood(k, nextIteration);    
        }
    }
}
