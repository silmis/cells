#include "common.h"
#include "Grid.h"
#include "Ruleset.h"
#include "Simulator.h"
#include "ImageMaker.h"

using namespace std;


int main ()
{
    Grid *grida = new Grid(1920, "r2");
    /*grida->set_grid(904,1);
    grida->set_grid(763,1);
    grida->set_grid(332,1);
    grida->set_grid(218,1);
    grida->set_grid(365,1);*/
    cout << "Grid A contains: \n";
    for (int i=0; i<grida->get_size(); i++) 
    {
        cout << to_string(grida->get_grid()[i]) + " ";
    }
    cout << "\n";
    
    //Ruleset * rs = new Ruleset("rule110", 3, 2, "01110110");
    //Ruleset * rs = new Ruleset("rule184", 3, 2, "00011101"); 
    //Ruleset * rs = new Ruleset("rule30", 3, 2, "01111000");
    //Ruleset * rs = new Ruleset("rule106", 3, 2, "01010110");
    //Ruleset * rs = new Ruleset("rule105", 3, 2, "10010110");
    //Ruleset * rs = new Ruleset("rule45", 3, 2, "10110100");
    Ruleset * rs = new Ruleset("rule150", 3, 2, "01101001");
    rulemap * rules = rs->get_rules();
    cout << "ruleset: " << rs->get_rule_name() << endl;
    for (int i=0; i<rs->get_nroOfNbhs(); i++)
    {
        string nbh = (*(rs->get_neighbourhoods()))[i];
        cout << nbh + ": " + (*rules)[nbh] << endl;
    }
    
    Simulator *s = new Simulator(rs, grida, 1080);
    ImageMaker *im = new ImageMaker(s);
    im->make_img();
    return 0;
}
