/**
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 * 2015/07
 * 16 ms
 */

class Solution
{
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        int rows = matrix.size();
        if(rows <= 0)
            return false;
        int cols = matrix[0].size();
        if(cols <= 0)
            return false;
        
        int begin = 0;
        int end = rows * cols - 1;
        int mid = (begin + end) / 2;
        while(mid > begin && mid < end)
        {
            if(target == matrix[end / cols][end % cols] || \
              target == matrix[begin / cols][begin % cols] || \
              target == matrix[mid / cols][mid % cols])
                return true;
            if(target > matrix[end / cols][end % cols] || target < matrix[begin / cols][begin % cols])
                return false;
            if(target > matrix[mid / cols][mid % cols])
                begin = mid;
            else
                end = mid;
            mid = (begin + end) / 2;
        }
        if(target == matrix[end / cols][end % cols] || \
          target == matrix[begin / cols][begin % cols] || \
          target == matrix[mid / cols][mid % cols])
            return true;
        return false;
    }
};
