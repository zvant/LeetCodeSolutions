/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 * 2015/08
 * 4 ms
 */

class Solution
{
private:
    void maxHeapAdj(vector<int> & nums, int begin, int n)
    {
        int idx = (begin + 1) * 2 - 1;
        while(idx < n)
        {
            if(idx + 1 < n && nums[idx] < nums[idx + 1])
                idx ++;
            if(nums[idx] > nums[begin])
            {
                int tmp = nums[idx];
                nums[idx] = nums[begin];
                nums[begin] = tmp;
                begin = idx;
                idx = (idx + 1) * 2 - 1;
            }
            else
                break;
        }
    }
public:
    int findKthLargest(vector<int> & nums, int k)
    {
        int n = nums.size();
        if(n <= 0 || k <= 0 || k > n)
            return -1;
        for(int idx = n / 2 - 1; idx >= 0; idx --)
            maxHeapAdj(nums, idx, n);
        for(int rest = n; rest > n - k + 1; )
        {
            int tmp = nums[rest - 1];
            nums[rest - 1] = nums[0];
            nums[0] = tmp;
            rest --;
            maxHeapAdj(nums, 0, rest);
        }
        return nums[0];
    }
};
