/**
 * https://leetcode.com/problems/unique-paths/description/
 * 2015/09
 * 0 ms
 */

class Solution
{
private:
    vector<vector<int> > known_paths;
    
    int getNumPaths(int row, int col)
    {
        if(known_paths[row][col] > 0)
            return known_paths[row][col];
        
        int count = getNumPaths(row - 1, col) + getNumPaths(row, col - 1);
        known_paths[row][col] = count;
        
        return count;
    }
public:
    int uniquePaths(int m, int n)
    {
        if(m <= 0 || n <= 0)
            return 0;
        
        known_paths.resize(m + 1);
        for(vector<int> & row : known_paths)
        {
            row.resize(n + 1);
            for(int & i : row)
                i = 0;
        }
        for(int idx = 1; idx <= n; idx ++)
            known_paths[1][idx] = 1;
        for(int idx = 1; idx <= m; idx ++)
            known_paths[idx][1] = 1;
        
        return getNumPaths(m, n);
    }
};
