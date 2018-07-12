/**
 * https://leetcode.com/problems/optimal-division/description/
 * 2017/05
 * 3 ms
 */

class Solution
{
public:
    string optimalDivision(vector<int>& nums)
    {
        int max_len = 20 * nums.size();
        char * buff = new char[max_len];
        if(nums.size() <= 1)
        {
            snprintf(buff, max_len, "%d", nums[0]);
        }
        if(nums.size() == 2)
        {
            snprintf(buff, max_len, "%d/%d", nums[0], nums[1]);
        }
        if(nums.size() >= 3)
        {
            int pos = snprintf(buff, max_len, "%d/(", nums[0]);
            for(int idx = 1; idx < nums.size(); idx ++)
            {
                pos += snprintf(buff + pos, max_len - pos, "%d/", nums[idx]);
            }
            buff[-- pos] = ')';
        }
        string result(buff);
        delete[] buff;
        return result;
    }
};
