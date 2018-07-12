/**
 * https://leetcode.com/problems/island-perimeter/description/
 * 2017/02
 * 129 ms
 */

class Solution
{
public:
    int islandPerimeter(vector<vector<int> > & grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int inner_boarder = 0;
        for(int row = 0; row < m - 1; row ++)
        {
            for(int col = 0; col < n - 1; col ++)
            {
                if(grid[row][col])
                {
                    count ++;
                    inner_boarder += grid[row][col + 1] + grid[row + 1][col];
                }
            }
        }
        for(int col = 0; col < n - 1; col ++)
        {
            if(grid[m - 1][col])
            {
                count ++;
                inner_boarder += grid[m - 1][col + 1];
            }
        }
        for(int row = 0; row < m - 1; row ++)
        {
            if(grid[row][n - 1])
            {
                count ++;
                inner_boarder += grid[row + 1][n - 1];
            }
        }
        count += grid[m - 1][n - 1];
        return count * 4 - 2 * inner_boarder;
    }
};
