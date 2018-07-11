/**
 * https://leetcode.com/problems/next-permutation/description/
 * 2015/08
 * 12 ms
 */

class Solution
{
private:
public:
    void nextPermutation(vector<int> & nums)
    {
        if(nums.size() <= 1)
            return;
        
        int idx = nums.size() - 1;
        while(idx > 0)
        {
            if(nums[idx] > nums[idx - 1])
                break;
            idx --;
        }
        if(idx == 0)
            reverse(nums.begin(), nums.end());
        else
        {
            sort(nums.begin() + idx, nums.end());
            int next;
            for(next = idx; next < nums.size(); next ++)
                if(nums[next] > nums[idx - 1])
                    break;
            int tmp = nums[next];
            nums[next] = nums[idx - 1];
            nums[idx - 1] = tmp;
        }
    }
};
