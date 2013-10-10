#include "Simulator.h"

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
void Simulator::run_simulation()
{
    Grid *nextIteration = m_inputGrid;
    Grid *temp;
    int howMany = 0;
    for ( int i=0; i<m_iterations; i++ )
    {   
        temp = nextIteration;
        gridPtr gptr(temp);
        m_result->push_back(std::move(gptr));
        delete nextIteration;
        Grid *nextIteration = new Grid(m_inputGrid->get_size());
        for ( int k=0; k<m_inputGrid->get_size(); k++ )
        {
            howMany++; 
        }
    }
    std::cout << howMany << std::endl;
}
