/*
ID: kzz19941
TASK: barn1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

int main()
{
    std::ofstream fout("barn1.out");
    std::ifstream fin("barn1.in");
    
    int M, S, C;
    fin >> M >> S >> C;
    std::vector<int> stalls;
    stalls.resize(C);
    for(int idx = 0; idx < C; idx ++)
    {
        fin >> stalls[idx];
    }
    std::sort(stalls.begin(), stalls.end());
    
    int cost = 1;
    int n_seg = 1;
    std::vector<int> gaps;
    for(int idx = 1; idx < C; idx ++)
    {
        cost ++;
        if(stalls[idx] > stalls[idx - 1])
        {
            gaps.push_back(stalls[idx] - stalls[idx - 1] - 1);
            n_seg ++;
        }
    }
    std::sort(gaps.begin(), gaps.end());
    
    //std::cout << n_seg << " " << gaps.size();
    
    int idx = 0;
    while(n_seg > M)
    {
        cost += gaps[idx];
        idx ++;
        n_seg --;
    }
    fout << cost << std::endl;
    
    return 0;
}
