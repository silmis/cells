#ifndef __SIMULATOR_H_INCLUDED__
#define __SIMULATOR_H_INCLUDED__

#include <memory>
#include "common.h"
#include "Grid.h"
#include "Ruleset.h"

typedef std::unique_ptr<Grid> gridPointer;
typedef std::vector<gridPointer> lifetime;

class Simulator
{
    private:
        Ruleset *m_ruleset;
        Grid *m_inputGrid;
        int m_iterations;
        lifetime *m_result;
        string get_neighbourhood(int index, Grid *grid);
    public:
        Simulator(Ruleset *ruleset, Grid *inputGrid, int iterations);
        ~Simulator();
        void run_simulation();
                
};

#endif
