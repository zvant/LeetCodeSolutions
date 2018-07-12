/**
 * https://leetcode.com/problems/jewels-and-stones/description/
 * 2018/07
 * 4 ms
 */

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        std::unordered_set<char> Js;
        for(int idx = 0; idx < J.length(); idx ++)
        {
            Js.insert(J[idx]);
        }
        int count = 0;
        for(int idx = 0; idx < S.length(); idx ++)
        {
            if(Js.count(S[idx]) > 0)
            {
                count ++;
            }
        }
        return count;
    }
};
