#include <math.h>
#include "Ruleset.h"

Ruleset::Ruleset(std::string ruleName, int neighbourhoodSize, 
    int numberOfStates, std::string rule) 
{
    rulemap *r = new rulemap; 
    this->rules = r;
    this->ruleName = ruleName;
    this->rule = rule;
    this->neighbourhoodSize = neighbourhoodSize;
    this->numberOfStates = numberOfStates;
    int numberOfNbhs = pow((float)numberOfStates, neighbourhoodSize);
    this->numberOfNbhs = numberOfNbhs;
    generate_neighbourhoods();
    populate_rule_map();
}
Ruleset::~Ruleset()
{
    delete rules;
    delete neighbourhoods;
}

void Ruleset::generate_neighbourhoods()
{
    neighbourhoods = new strVector;
    string nh="";
    char letters[] = "abcdefghijklmnopqrstuvxyz";
    int iterationsLeft = neighbourhoodSize;
    nbh_recursion(nh, numberOfStates, iterationsLeft, letters);
}

void Ruleset::nbh_recursion(string nh, int numberOfStates, 
        int iterationsLeft, char *letters)
{
    if (nh.length() == neighbourhoodSize)
    {
        neighbourhoods->push_back(nh);
    }
    if (iterationsLeft == 0) 
        return;
    iterationsLeft--;
    for (int i=0; i<numberOfStates; i++) 
    {
        nbh_recursion(nh + letters[i], numberOfStates, 
            iterationsLeft, letters);
    }
}

void Ruleset::populate_rule_map()
{
    for (int i=0; i<numberOfNbhs; i++)
    {
        string r(1,rule[i]);
        string nbh = (*neighbourhoods)[i];
        (*rules)[nbh] = r;
    }
}
