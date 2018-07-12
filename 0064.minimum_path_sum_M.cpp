/**
 * https://leetcode.com/problems/minimum-path-sum/description/
 * 2015/09
 * 32 ms
 */

class Solution
{
private:
    int m, n;
    vector<vector<int> > * board;
    vector<vector<int> > sum_matrix;
    int findMinPathTo(int row, int col)
    {
        if(row < 0 || row >= m || col < 0 || col >= n)
            return INT_MAX;
        
        if(sum_matrix[row][col] >= 0)
            return sum_matrix[row][col];
        
        int sum_left = findMinPathTo(row, col - 1);
        int sum_above = findMinPathTo(row - 1, col);
        sum_matrix[row][col] = (* board)[row][col] + ((sum_left < sum_above) ? sum_left : sum_above);
        return sum_matrix[row][col];
    }
public:
    int minPathSum(vector<vector<int> > & grid)
    {
        if((m = grid.size()) <= 0 || (n = grid[0].size()) <= 0)
            return -1;
        
        board = &grid;
        sum_matrix.resize(m);
        for(vector<int> & v : sum_matrix)
        {
            v.resize(n);
            for(int & i : v)
                i = -1;
        }
        sum_matrix[0][0] = grid[0][0];
        
        return findMinPathTo(m - 1, n - 1);
    }
};
