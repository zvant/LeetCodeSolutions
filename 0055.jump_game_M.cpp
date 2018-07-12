/**
 * https://leetcode.com/problems/jump-game/description/
 * 2015/09
 * 16 ms
 */

class Solution
{
private:
    int size;
    vector<bool> positions;
public:
    bool canJump(vector<int> & nums)
    {
        if((size = nums.size()) <= 0)
            return false;
        if(size <= 1)
            return true;
        positions.clear();
        for(int idx = 0; idx < size; idx ++)
            positions.push_back(true);
        /*for(int idx = 0; idx < size - 1; idx ++)
            if(nums[idx] == 0)
                positions[idx] = false;*/
        
        for(int idx = size - 2; idx >= 0; idx --)
        {
            if(nums[idx] == 0)
            {
                positions[idx] = false;
                int last = idx - 1;
                while(last >= 0)
                {
                    if(idx - last >= nums[last])
                    {
                        positions[last] = false;
                        last --;
                    }
                    else
                        break;
                }
                idx = last;
            }
        }
        
        return positions[0];
    }
};
