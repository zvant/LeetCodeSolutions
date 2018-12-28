/*
ID: kzz19941
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream fout("ride.out");
    std::ifstream fin("ride.in");
    
    std::string comet, group;
    int magic = 47;
    int comet_mod, group_mod;
    comet_mod = group_mod = 1;
    
    fin >> comet >> group;
    
    for(int idx = 0; idx < comet.length(); idx ++)
    {
        comet_mod = (comet_mod * (1 + comet[idx] - 'A')) % magic;
    }
    
    for(int idx = 0; idx < group.length(); idx ++)
    {
        group_mod = (group_mod * (1 + group[idx] - 'A')) % magic;
    }
    
    if(group_mod == comet_mod)
    {
        fout << "GO\n";
    }
    else
    {
        fout << "STAY\n";
    }
    
    return 0;
}
