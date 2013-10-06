#include "common.h"

class Run
{
    typedef std::vector<Grid> lifetime;
    public:
        Run(Ruleset *ruleset, lifetime lifetimeGrid);
        ~Run();
}

