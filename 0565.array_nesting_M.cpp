/**
 * https://leetcode.com/problems/array-nesting/
 * 2018/12
 * 40 ms
 */

class Solution
{
public:
    int arrayNesting(vector<int> & nums)
    {
        int max_len = 0;
        int s_idx = 0;
        while(s_idx < nums.size())
        {
            if(max_len >= (1 + nums.size()) / 2)
            {
                break;
            }
            while(s_idx < nums.size() && nums[s_idx] < 0)
            {
                s_idx ++;
            }
            if(s_idx >= nums.size())
            {
                break;
            }
            
            int len = 1;
            for(int idx = nums[s_idx]; idx != s_idx; )
            {
                int tmp = nums[idx];
                nums[idx] = -1;
                idx = tmp;
                len ++;
            }
            nums[s_idx] = -1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
