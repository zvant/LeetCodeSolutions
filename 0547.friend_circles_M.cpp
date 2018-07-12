/**
 * https://leetcode.com/problems/friend-circles/description/
 * 2017/04
 * 29 ms
 */

class Solution
{
private:
    int num;
    vector<bool> included;
    
    void findFriends(vector<vector<int>> & M, int idx)
    {
        for(int friend_idx = 0; friend_idx < num; friend_idx ++)
        {
            if(M[idx][friend_idx] == 1 && ! included[friend_idx])
            {
                included[friend_idx] = true;
                M[idx][friend_idx] = M[friend_idx][idx] = 0;
                findFriends(M, friend_idx);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>> & M)
    {
        num = M.size();
        included = vector<bool>(num, false);
        for(int idx = 0; idx < num; idx ++)
        {
            M[idx][idx] = 0;
        }
        int result = 0;
        for(int idx = 0; idx < num; idx ++)
        {
            if(! included[idx])
            {
                included[idx] = true;
                result ++;
                findFriends(M, idx);
            }
        }
        return result;
    }
};
