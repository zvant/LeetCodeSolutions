/**
 * https://leetcode.com/problems/3sum/
 * 2020/01
 * 212 ms
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> triples;
        unordered_map<int, int> counts;
        for(auto it = nums.begin(); it != nums.end(); it ++)
        {
            if(counts.count(* it) > 0)
            {
                counts[* it] ++;
            }
            else
            {
                counts[* it] = 1;
            }
        }
        int index = 0;
        for(auto it1 = counts.begin(); it1 != counts.end(); it1 ++)
        {
            index ++;
            int n1 = it1 -> first;
            int c1 = it1 -> second;
            if(c1 >= 3 && n1 == 0)
            {
                triples.push_back({0, 0, 0});
            }
            if(c1 >= 2 && n1 != 0 && counts.count(0 - n1 - n1) > 0)
            {
                triples.push_back({n1, n1, 0 - n1 - n1});
            }
            int index2 = 0;
            for(auto it2 = counts.begin(); it2 != counts.end(); it2 ++)
            {
                index2 ++;
                if(index2 <= index)
                {
                    continue;
                }
                int n2 = it2 -> first;
                if(n1 * 2 < -1 * n2 && n2 * 2 < -1 * n1 && counts.count(0 - n1 - n2) > 0)
                {
                    triples.push_back({n1, n2, 0 - n1 - n2});
                }
            }
        }
        return triples;
    }
};
