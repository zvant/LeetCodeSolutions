/**
 * https://leetcode.com/problems/group-anagrams/
 * 2019/08
 * 49 ms
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<int>> table;
        for(int i = 0; i < strs.size(); i ++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            table[s].push_back(i);
        }
        vector<vector<string>> groups;
        for(auto it = table.begin(); it != table.end(); it ++)
        {
            vector<string> g;
            for(int i = 0; i < (it -> second).size(); i ++)
            {
                g.push_back(strs[(it -> second)[i]]);
            }
            groups.push_back(g);
        }
        return groups;
    }
};
