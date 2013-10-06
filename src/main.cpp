#include "common.h"
#include "Grid.h"
#include "Ruleset.h"


using namespace std;


int main ()
{
    cout << "cell simulator cells\n";
    Grid *grida = new Grid();
    Grid *gridb = new Grid(300);
    cout << "Grid A is " + to_string(grida->get_size()) + "\n";
    cout << "Grid B is " + to_string(gridb->get_size()); 
    cout << "\n";

    Ruleset * rs = new Ruleset("myName", 3, 2, "abbbabba");
    rulemap * rules = rs->get_rules();
    cout << "ruleset: " << endl;
    for (int i=0; i<rs->get_nroOfNbhs(); i++)
    {
        string nbh = (*(rs->get_neighbourhoods()))[i];
        cout << nbh + ": " + (*rules)[nbh] << endl;
    }
    return 0;
}
