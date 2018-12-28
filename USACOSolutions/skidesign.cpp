/*
ID: kzz19941
TASK: skidesign
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
    std::ofstream fout("skidesign.out");
    std::ifstream fin("skidesign.in");
    
    int N;
    std::vector<int> heights, moves;
    fin >> N;
    heights.resize(N);
    for(int idx = 0; idx < N; idx ++)
    {
        fin >> heights[idx];
    }
    std::sort(heights.begin(), heights.end());
    
    int idx = 0;
    int diff;
    moves.resize(N);
    while((diff = heights[N - 1 - idx] - heights[idx] - 17) > 0)
    {
        std::cout << std::endl << cost << std::endl;
        for(int idx = 0; idx < N / 2; idx ++)
        {
            std::cout << heights[idx] << "|";
        }
        std::cout << std::endl;
        for(int idx = N - 1; idx >= N / 2; idx --)
        {
            std::cout << heights[idx] << "|";
        }
        
        int move1 = diff / 2;
        int move2;
        if(0 == (diff % 2))
        {
            move2 = diff / 2;
        }
        else
        {
            move2 = diff / 2 + 1;
        }
        heights[idx] += move1;
        moves[idx] = move1;
        heights[N - 1 - idx] -= move2;
        moves[N - 1 - idx] = move2;
        
        idx ++;
    }
    fout << cost << std::endl;
    
    return 0;
}
