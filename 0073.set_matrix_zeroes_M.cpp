/**
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 * 2015/08
 * 84 ms
 */

class Solution
{
public:
    void setZeroes(vector<vector<int> >& matrix)
    {
        if(matrix.size() <= 0 || matrix[0].size() <= 0)
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row_zero;
        row_zero.clear();
        for(int i = 0; i < m; i ++)
            row_zero.push_back(1);
        vector<int> col_zero;
        col_zero.clear();
        for(int i = 0; i < n; i ++)
            col_zero.push_back(1);
        
        for(int row = 0; row < m; row ++)
        {
            for(int col = 0; col < n; col ++)
            {
                if(matrix[row][col] == 0)
                {
                    row_zero[row] = 0;
                    col_zero[col] = 0;
                }
            }
        }
        for(int row = 0; row < m; row ++)
        {
            if(0 == row_zero[row])
                for(int col = 0; col < n; col ++)
                    matrix[row][col] = 0;
        }
        for(int col = 0; col < n; col ++)
        {
            if(0 == col_zero[col])
                for(int row = 0; row < m; row ++)
                    matrix[row][col] = 0;
        }
    }
};
