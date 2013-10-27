#include "common.h"
#include "Grid.h"
#include "Ruleset.h"
#include "Simulator.h"
#include "ImageMaker.h"

using namespace std;


int main ()
{
    Grid *grida = new Grid(1920);
    grida->set_grid(904,1);
    grida->set_grid(763,1);
    grida->set_grid(332,1);
    grida->set_grid(218,1);
    grida->set_grid(365,1);
    //grida->set_grid(7,1);
    //grida->set_grid(9,1);
    cout << "Grid A is " + to_string(grida->get_size()) + " long\n";
    cout << "\n";
    cout << "Grid A[5]: " + to_string(grida->get_grid()[5]) + "\n";
    cout << "Grid A contains: \n";
    for (int i=0; i<grida->get_size(); i++) 
    {
        cout << to_string(grida->get_grid()[i]) + " ";
    }
    cout << "\n";
    Ruleset * rs = new Ruleset("rule110", 3, 2, "01110110");
    rulemap * rules = rs->get_rules();
    cout << "ruleset: " << endl;
    for (int i=0; i<rs->get_nroOfNbhs(); i++)
    {
        string nbh = (*(rs->get_neighbourhoods()))[i];
        cout << nbh + ": " + (*rules)[nbh] << endl;
    }
    
    Simulator *s = new Simulator(rs, grida, 1080);
    lifetime *lt = s->get_result();
    //std::cout << "lifetime len " << lt->size() << std::endl;
    //std::cout << "lt 5th row "; 
    //lt->at(5)->print();   
    ImageMaker *im = new ImageMaker(lt);
    im->make_img();
     
    //delete grida;
    //delete gridb;
    //delete rs;
    //delete s;
    return 0;
}
