#include "common.h"
#include "Grid.h"
#include "Ruleset.h"
#include "Simulator.h"

using namespace std;


int main ()
{
    cout << "cell simulator cells\n";
    Grid *grida = new Grid(100);
    Grid *gridb = grida;
    grida->set_grid(5,5);
    gridb->set_grid(5,10);
    cout << "Grid A is " + to_string(grida->get_size()) + "\n";
    cout << "Grid B is " + to_string(gridb->get_size()); 
    cout << "\n";
    cout << "Grid A[5]: " + to_string((grida->get_grid())[5]) + "\n";
    cout << "Grid B[5]: " + to_string((gridb->get_grid())[5]) + "\n";

    Ruleset * rs = new Ruleset("myName", 3, 2, "abbbabba");
    rulemap * rules = rs->get_rules();
    cout << "ruleset: " << endl;
    for (int i=0; i<rs->get_nroOfNbhs(); i++)
    {
        string nbh = (*(rs->get_neighbourhoods()))[i];
        cout << nbh + ": " + (*rules)[nbh] << endl;
    }
    
    Simulator *s = new Simulator(rs, grida, 100);
    s->run_simulation();
  
    //delete grida;
    //delete gridb;
    //delete rs;
    //delete s;
    return 0;
}
