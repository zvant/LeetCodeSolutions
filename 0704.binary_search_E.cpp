/**
 * https://leetcode.com/problems/binary-search/
 * 2019/06
 * 48 ms
 */

class Solution
{
public:
    int search(vector<int> & nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[left] == target)
        {
            return left;
        }
        if(nums[right] == target)
        {
            return right;
        }

        while(true)
        {
            if(left + 1 >= right)
            {
                return -1;
            }

            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
    }
};