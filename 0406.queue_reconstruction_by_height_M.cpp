/**
 * https://leetcode.com/problems/queue-reconstruction-by-height/
 * 2018/12
 * 44 ms
 */

bool comp(const pair<int, int> & p1, const pair<int, int> & p2)
{
    if(p1.first != p2.first)
    {
        return p1.first > p2.first;   
    }
    else
    {
        return p1.second < p2.second;
    }
}

class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> & people)
    {
        if(people.size() < 2)
        {
            return people;
        }
        
        sort(people.begin(), people.end(), comp);
        for(int idx = 0; idx < people.size(); idx ++)
        {
            if(idx != people[idx].second)
            {
                rotate(people.begin() + people[idx].second, people.begin() + idx, people.begin() + idx + 1);
            }
        }
        
        return people;
    }
};
