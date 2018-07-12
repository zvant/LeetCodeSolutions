/**
 * https://leetcode.com/problems/shortest-distance-to-a-character/description/
 * 2018/07
 * 8 ms
 */

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        int len = S.length();
        vector<int> dists(len, len + 20);
        int C_pos = S.find(C);
        while(C_pos < len)
        {
            dists[C_pos] = 0;
            // backward
            int dist = 1;
            int idx = C_pos - 1;
            while(idx >= 0 && dist < dists[idx])
            {
                dists[idx] = dist;
                idx --;
                dist ++;
            }
            // foreward
            dist = 1;
            idx = C_pos + 1;
            while(idx < len && S[idx] != C)
            {
                dists[idx] = dist;
                dist ++;
                idx ++;
            }
            ////
            if(idx >= len)
            {
                break;
            }
            if(S[idx] == C)
            {
                C_pos = idx;
            }
        }
        return dists;
    }
};
