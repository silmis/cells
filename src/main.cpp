#include <unistd.h>
#include <stdlib.h>

#include "common.h"
#include "Grid.h"
#include "Ruleset.h"
#include "Simulator.h"
#include "ImageMaker.h"

using namespace std;

string current_directory() 
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    string s(cwd);
    return s;
}

int main (int argc, char **argv)
{
    int gridLength = 0; 
    int iterations = 0;
    int rule = 0;
    string outPath = "";

    int flags;
    while ((flags = getopt(argc, argv, "g:i:r:o:")) != -1)
    {
        switch (flags)
        {
            case 'g':
                gridLength = atoi(optarg);
                break;
            case 'i':
                iterations = atoi(optarg);
                break;
            case 'r':
                rule = atoi(optarg);
                break;
            case 'o':
                if ((optarg[0] != '/') && (optarg[0] != '~'))
                {
                    string cwd = current_directory();
                    string opt(optarg);
                    outPath = cwd + "/" + optarg;  
                }
                else outPath = optarg;
                break;
            default:
                abort();
        }
    }
    if (gridLength <= 0)
    {
        cout << "Grid length (-g) is a mandatory argument\n";
        return 1;
    }
    else if (iterations <= 0)
    {
        cout << "Iteration count (-i) is a mandatory argument\n";
        return 1;
    }
    else if (outPath == "")
    {
        outPath = current_directory();
    }


    Grid *grida = new Grid(gridLength, "r2");
    
    /*grida->set_grid(904,1);
    grida->set_grid(763,1);
    grida->set_grid(332,1);
    grida->set_grid(218,1);
    grida->set_grid(365,1);*/
    
    Ruleset *rs;
    if (rule == 110)
        rs = new Ruleset("rule110", 3, 2, "01110110");
    else if (rule == 184)
        rs = new Ruleset("rule184", 3, 2, "00011101"); 
    else if (rule == 30)
        rs = new Ruleset("rule30", 3, 2, "01111000");
    else if (rule == 106)
        rs = new Ruleset("rule106", 3, 2, "01010110");
    else if (rule == 105)
        rs = new Ruleset("rule105", 3, 2, "10010110");
    else if (rule == 45)
        rs = new Ruleset("rule45", 3, 2, "10110100");
    else if (rule == 150)
        rs = new Ruleset("rule150", 3, 2, "01101001");
    else
        rs = new Ruleset("rule110", 3, 2, "01110110");
 
    rulemap * rules = rs->get_rules();
    
    cout << "Grid length: " + to_string(gridLength) + 
    "\nIterations: " + to_string(iterations) + 
    "\nRule: " + rs->get_rule_name() +
    "\nOutput to: " + outPath + "\n";
    for (int i=0; i<rs->get_nroOfNbhs(); i++)
    {
        string nbh = (*(rs->get_neighbourhoods()))[i];
        cout << nbh + ": " + (*rules)[nbh] + " | ";
    }
    cout << endl;
    
    Simulator *s = new Simulator(rs, grida, iterations);
    ImageMaker *im = new ImageMaker(s);
    im->make_img(outPath);
    return 0;
}


