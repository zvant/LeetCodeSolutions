/**
 * https://leetcode.com/problems/reshape-the-matrix/description/
 * 2017/05
 * 38 ms
 */

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        int m = nums.size();
        int n = nums[0].size();
        int size = m * n;
        if(r * c != size)
        {
            return nums;
        }
        vector<vector<int>> result;
        for(int row = 0; row < r; row ++)
        {
            result.push_back(vector<int>(c, 0));
        }
        for(int idx = 0; idx < size; idx ++)
        {
            result[idx / c][idx % c] = nums[idx / n][idx % n];
        }
        return result;
    }
};
