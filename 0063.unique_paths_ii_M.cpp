/**
 * https://leetcode.com/problems/unique-paths-ii/description/
 * 2015/09
 * 4 ms
 */

class Solution
{
private:
    vector<vector<int> > known_paths;
    int m, n;
    vector<vector<int> > * grid;
    
    int getNumPathsFrom(int row, int col)
    {
        if(row >= m || col >= n)
            return 0;

        if(known_paths[row][col] > 0)
            return known_paths[row][col];

        int count = 0;
        if(row + 1 < m && (* grid)[row + 1][col] == 0)
            count += getNumPathsFrom(row + 1, col);
        if(col + 1 < n && (* grid)[row][col + 1] == 0)
            count += getNumPathsFrom(row, col + 1);
        known_paths[row][col] = count;

        return count;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int> > & obstacleGrid)
    {
        if((m = obstacleGrid.size()) <= 0 || (n = obstacleGrid[0].size()) <= 0)
            return 0;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        
        known_paths.resize(m);
        for(vector<int> & row : known_paths)
        {
            row.resize(n);
            for(int & i : row)
                i = 0;
        }
        known_paths[m - 1][n - 1] = 1;
        
        if(m > 5 && n > 5)
        {
            for(int idx = m - 2; idx >= 0; idx --)
                if(obstacleGrid[idx + 1][n - 1] == 1)
                    obstacleGrid[idx][n - 1] = 1;
            for(int idx = n - 2; idx >= 0; idx --)
                if(obstacleGrid[m - 1][idx + 1] == 1)
                    obstacleGrid[m - 1][idx] = 1;
            for(int row = m - 2; row >= 0; row --)
                for(int col = n - 2; col >= 0; col --)
                    if(obstacleGrid[row + 1][col] == 1 && obstacleGrid[row][col + 1] == 1)
                        obstacleGrid[row][col] = 1;
        }
        grid = &obstacleGrid;
        
        return getNumPathsFrom(0, 0);
    }
};
