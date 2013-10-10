#ifndef __SIMULATOR_H_INCLUDED__
#define __SIMULATOR_H_INCLUDED__

#include <memory>
#include "common.h"
#include "Grid.h"
#include "Ruleset.h"

typedef std::unique_ptr<Grid> gridPtr;
typedef std::vector<gridPtr> lifetime;

class Simulator
{
    private:
        Ruleset *m_ruleset;
        Grid *m_inputGrid;
        int m_iterations;
        lifetime *m_result;
    public:
        Simulator(Ruleset *ruleset, Grid *inputGrid, int iterations);
        ~Simulator();
        void run_simulation();
                
};
