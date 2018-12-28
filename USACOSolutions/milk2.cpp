/*
ID: kzz19941
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

bool comp(const std::pair<int, int> & t1, const std::pair<int, int> & t2)
{
    return t1.first < t2.first;
}

int main()
{
    std::ofstream fout("milk2.out");
    std::ifstream fin("milk2.in");
    
    int N;
    std::vector<std::pair<int, int>> intervals;
    fin >> N;
    intervals.resize(N);
    for(int idx = 0; idx < N; idx ++)
    {
        fin >> intervals[idx].first >> intervals[idx].second;
    }
    std::sort(intervals.begin(), intervals.end(), comp);
    
    int max_milk = 0;
    int max_idle = 0;
    
    int idx = 0;
    while(idx < N)
    {
        int start = intervals[idx].first;
        int end = intervals[idx].second;
        while(idx < N && intervals[idx].first <= end)
        {
            end = std::max(end, intervals[idx].second);
            idx ++;
        }
        max_milk = std::max(max_milk, end - start);
        if(idx < N)
        {
            max_idle = std::max(max_idle, intervals[idx].first - end);
        }
    }
    fout << max_milk << " " << max_idle << std::endl;
    
    return 0;
}
