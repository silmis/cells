#ifndef __SIMULATOR_H_INCLUDED__
#define __SIMULATOR_H_INCLUDED__

#include "common.h"
class Ruleset;
class Grid;

class Simulator
{
    private:
        Ruleset *m_ruleset;
        Grid *m_inputGrid;
        int m_iterations;
        lifetime *m_result;
        string get_neighbourhood(int index, Grid *grid);
        string toroid_left_side(int index, int overlap, int gridSize, string key);
        string toroid_right_side(int index, int overlap, int gridSize, string key);
        void run_simulation();
    public:
        Simulator(Ruleset *ruleset, Grid *inputGrid, int iterations);
        ~Simulator();
        Ruleset * get_ruleset() { return m_ruleset; }
        lifetime * get_result() {
            if (m_result->size() < 1)
            {
                run_simulation();
                return m_result;
            } 
            else { return m_result; } 
        }; 
};

#endif
