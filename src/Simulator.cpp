#include "Simulator.h"
#include "common.h"

Simulator::Simulator(Ruleset *ruleset, Grid *inputGrid, int iterations)
{
    this->ruleset = ruleset;
    this->inputGrid = inputGrid;
    this->iterations = iterations;
    run_simulation();
}
Simulator::~Simulator()
{
    delete ruleset;
    delete inputGrid;
}
void Simulator::run_simulation()
{
    
}
