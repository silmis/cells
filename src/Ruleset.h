#ifndef __RULESET_H_INCLUDED__
#define __RULESET_H_INCLUDED__

#include "common.h"

class Ruleset {
    private:
        string m_ruleName;
        string m_rule;
        int m_neighbourhoodSize;
        int m_numberOfStates;
        int m_numberOfNbhs;
        rulemap * m_rulemap;
        strVector * m_neighbourhoods;
        void generate_neighbourhoods();
        void nbh_recursion(string nh, int iterationsLeft, char *letters);
        void populate_rule_map();   
    public:
        Ruleset(string ruleName, int neighbourhoodSize, 
            int numberOfStates, string rule);
        ~Ruleset();
        int get_neighbourhoodSize() { return m_neighbourhoodSize; }
        int get_nroOfStates() { return m_numberOfStates; }
        int get_nroOfNbhs() { return m_numberOfNbhs; }
        strVector * get_neighbourhoods() { return m_neighbourhoods; }
        string get_rule_name() { return m_ruleName; }
        rulemap * get_rules() { return m_rulemap; }
        void printNH();
};
#endif
