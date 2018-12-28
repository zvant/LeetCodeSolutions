/*
ID: kzz19941
TASK: milk
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> Farmer;

bool comp_pair(const Farmer & f1, const Farmer & f2)
{
    return f1.first < f2.first;
}

int main()
{
    std::ofstream fout("milk.out");
    std::ifstream fin("milk.in");
    
    int N, M;
    std::vector<Farmer> farmers;
    
    fin >> N >> M;
    farmers.resize(M);
    for(int idx = 0; idx < M; idx ++)
    {
        fin >> farmers[idx].first >> farmers[idx].second;
    }
    std::sort(farmers.begin(), farmers.end(), comp_pair);
    
    int cost = 0;
    int f_idx = 0;
    while(N > 0)
    {
        if(farmers[f_idx].second < N)
        {
            N -= farmers[f_idx].second;
            cost += farmers[f_idx].second * farmers[f_idx].first;
            f_idx ++;
        }
        else
        {
            cost += farmers[f_idx].first * N;
            break;
        }
    }
    fout << cost << std::endl;
    
    return 0;
}
