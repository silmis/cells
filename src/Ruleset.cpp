#include <math.h>
#include "Ruleset.h"

Ruleset::Ruleset(string ruleName, int neighbourhoodSize, 
    int numberOfStates, string rule) 
{
    rulemap *r = new rulemap; 
    m_rulemap = r;
    m_ruleName = ruleName;
    m_rule = rule;
    m_neighbourhoodSize = neighbourhoodSize;
    m_numberOfStates = numberOfStates;
    m_numberOfNbhs = pow((float)numberOfStates, neighbourhoodSize);
    generate_neighbourhoods();
    populate_rule_map();
}
Ruleset::~Ruleset()
{
    delete m_rulemap;
    delete m_neighbourhoods;
}

void Ruleset::generate_neighbourhoods()
{
    m_neighbourhoods = new strVector;
    string nh="";
    char states[] = "0123456789";
    int iterationsLeft = m_neighbourhoodSize;
    nbh_recursion(nh, iterationsLeft, states);
}

void Ruleset::nbh_recursion(string nh, int iterationsLeft, char *states)
{
    if (nh.length() == m_neighbourhoodSize)
    {
        m_neighbourhoods->push_back(nh);
    }
    if (iterationsLeft == 0) 
        return;
    iterationsLeft--;
    for (int i=0; i<m_numberOfStates; i++) 
    {
        nbh_recursion(nh + states[i], iterationsLeft, states);
    }
}

void Ruleset::populate_rule_map()
{
    for (int i=0; i<m_numberOfNbhs; i++)
    {
        string r(1, m_rule[i]);
        string nbh = (*m_neighbourhoods)[i];
        (*m_rulemap)[nbh] = r;
    }
}
