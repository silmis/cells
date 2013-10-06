#include "common.h"
#include "Grid.h"
#include "Ruleset.h"

class Simulator
{
    typedef std::vector<Grid> lifetime;
    private:
        Ruleset *ruleset;
        Grid *inputGrid;
        int iterations;
        void run_simulation();
    public:
        Simulator(Ruleset *ruleset, Grid *inputGrid, int iterations);
        ~Simulator();
                
};
