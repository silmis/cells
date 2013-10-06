#ifndef __RULESET_H_INCLUDED__
#define __RULESET_H_INCLUDED__

#include "common.h"

class Ruleset {
    private:
        string ruleName;
        string rule;
        int neighbourhoodSize;
        int numberOfStates;
        int numberOfNbhs;
        rulemap * rules;
        strVector * neighbourhoods;
        void generate_neighbourhoods();
        void nbh_recursion(string nh, int numberOfStates, 
            int iterationsLeft, char *letters);
        void populate_rule_map();   
    public:
        Ruleset(string ruleName, int neighbourhoodSize, 
            int numberOfStates, string rule);
        ~Ruleset();
        int get_neighbourhoodSize() { return this->neighbourhoodSize; }
        int get_nroOfStates() { return this->numberOfStates; }
        int get_nroOfNbhs() { return this->numberOfNbhs; }
        strVector * get_neighbourhoods() { return this->neighbourhoods; }
        string get_rule_name() { return this->ruleName; }
        rulemap * get_rules() { return rules; }
        void printNH();
};
#endif
