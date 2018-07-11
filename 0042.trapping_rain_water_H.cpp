/**
 * https://leetcode.com/problems/trapping-rain-water/description/
 * 2017/10
 */

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int N = height.size();
        int * max_heights = new int[N];
        int left_max = -1;
        for(int idx = 0; idx < N; idx ++)
        {
            if(height[idx] > left_max)
            {
                left_max = height[idx];
            }
            max_heights[idx] = left_max;
        }
        int right_max = -1;
        int sum = 0;
        for(int idx = N - 1; idx >= 0; idx --)
        {
            if(height[idx] > right_max)
            {
                right_max = height[idx];
            }
            if(max_heights[idx] > right_max)
            {
                max_heights[idx] = right_max;
            }
            if(max_heights[idx] > height[idx])
            {
                sum += max_heights[idx] - height[idx];
            }
        }
        delete[] max_heights;
        return sum;
    }
};
