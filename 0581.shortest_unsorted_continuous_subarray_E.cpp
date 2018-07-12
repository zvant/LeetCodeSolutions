/**
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 * 2017/06
 * 52 ms
 */

class Solution
{
public:
    int findUnsortedSubarray(vector<int> & nums)
    {
        int len = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int left = 0;
        while(left < len && nums[left] == sorted[left])
        {
            left ++;
        }
        if(left >= len - 1)
        {
            return 0;
        }
        int right = len - 1;
        while(right > left && nums[right] == sorted[right])
        {
            right --;
        }
        return right - left + 1;
    }
};
