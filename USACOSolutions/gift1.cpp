/*
ID: kzz19941
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::ofstream fout("gift1.out");
    std::ifstream fin("gift1.in");
    
    int np;
    std::vector<std::string> g_names;
    std::map<std::string, int> balance;
    
    fin >> np;
    g_names.resize(np);
    
    for(int idx = 0; idx < np; idx ++)
    {
        fin >> g_names[idx];
        balance[g_names[idx]] = 0;
    }
    
    std::string giver, receiver;
    
    while(fin >> giver)
    {
        int amount, n_rec;
        fin >> amount >> n_rec;
        if(amount <= 0)
        {
            continue;
        }
        
        amount = amount / n_rec;
        balance[giver] -= amount * n_rec;
        
        for(int idx = 0; idx < n_rec; idx ++)
        {
            fin >> receiver;
            balance[receiver] += amount;
        }
    }
    
    for(int idx = 0; idx < np; idx ++)
    {
        fout << g_names[idx] << " " << balance[g_names[idx]] << std::endl;
    }
    
    return 0;
}
