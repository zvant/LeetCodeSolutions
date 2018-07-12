/**
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 * 2017/06
 * 179 ms
 */

class Solution
{
public:
    double findMaxAverage(vector<int> & nums, int k)
    {
        double ave = 0.0;
        int start = 0;
        int end = 0;
        double k_double = k;
        while(end < k)
        {
            ave += nums[end] / k_double;
            end ++;
        }
        double max_ave = ave;
        int n = nums.size();
        while(end < n)
        {
            ave -= nums[start ++] / k_double;
            ave += nums[end ++] / k_double;
            if(ave > max_ave)
            {
                max_ave = ave;
            }
        }
        return max_ave;
    }
};
