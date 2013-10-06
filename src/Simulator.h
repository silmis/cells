#include "common.h"

class Simulator
{
    private:
        Ruleset *ruleset;
        Grid *inputGrid;
        int iterations;
        void run_simulation();
    public:
        Simulator(Ruleset *ruleset, Grid *inputGrid, int iterations);
        ~Simulator();
                
};
