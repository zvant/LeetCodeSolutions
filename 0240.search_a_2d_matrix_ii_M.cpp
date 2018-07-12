/**
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 * 2015/09
 * 464 ms
 */

class Solution
{
private:
    bool searchBinary(vector<int> & nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        if(target > nums[end] || target < nums[0])
            return false;
        
        while(end > begin)
        {
            if(nums[begin] == target || nums[end] == target)
                return true;
            int mid = (begin + end) / 2;
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        if(nums[begin] == target)
            return true;
        else
            return false;
    }
public:
    bool searchMatrix(vector<vector<int> > & matrix, int target)
    {
        int m, n;
        if((m = matrix.size()) <= 0 || (n = matrix[0].size()) <= 0)
            return false;
        int begin = 0;
        while(begin < m && matrix[begin][n - 1] < target)
            begin ++;
        int end = m - 1;
        while(end >= 0 && matrix[end][0] > target)
            end --;
        for(int row = begin; row <= end; row ++)
            if(searchBinary(matrix[row], target))
                return true;
        return false;
    }
};
