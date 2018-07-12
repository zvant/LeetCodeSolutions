/**
 * https://leetcode.com/problems/find-duplicate-file-in-system/description/
 * 2017/06
 * 95 ms
 */

class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        unordered_map<string, vector<string>> dups;
        for(int path_idx = 0; path_idx < paths.size(); path_idx ++)
        {
            const string & path = paths[path_idx];
            int idx = 0;
            while(path[idx] != ' ')
            {
                idx ++;
            }
            string dir = path.substr(0, idx) + "/";
            idx ++;
            int idx2 = idx + 1;
            while(idx < path.length())
            {
                while(path[idx2] != '(')
                {
                    idx2 ++;
                }
                string filename = dir + path.substr(idx, idx2 - idx);
                idx = idx2 + 1;
                while(path[idx2] != ')')
                {
                    idx2 ++;
                }
                string content = path.substr(idx, idx2 - idx);
                if(dups.count(content) < 1)
                {
                    dups[content] = vector<string>();
                }
                dups[content].push_back(filename);
                idx = idx2 + 2;
            }
        }
        vector<vector<string>> result;
        for(auto it = dups.begin(); it != dups.end(); it ++)
        {
            if((it -> second).size() > 1)
            {
                result.push_back(it -> second);
            }
        }
        return result;
    }
};
