/**
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 * 2016/10
 * 92 ms
 */

class Solution
{
private:
    int m, n, size;
    vector<vector<int> > grid;
    
    void checkFlowTo(vector<vector<int> > & matrix, bool * accessible, vector<int> & fringe)
    {
        while(! fringe.empty())
        {
            for(auto it = fringe.begin(); it != fringe.end(); it ++)
            {
                accessible[* it] = true;
            }
            vector<int> new_fringe;
            for(auto it = fringe.begin(); it != fringe.end(); it ++)
            {
                const int row = (* it) / n;
                const int col = (* it) % n;
                if(row - 1 >= 0 && matrix[row - 1][col] >= matrix[row][col])
                {
                    int new_idx = (row - 1) * n + col;
                    if(! accessible[new_idx])
        			    new_fringe.push_back(new_idx);
                }
                if(row + 1 < m  && matrix[row + 1][col] >= matrix[row][col])
                {
                    int new_idx = (row + 1) * n + col;
                    if(! accessible[new_idx])
        			    new_fringe.push_back(new_idx);
                }
                if(col - 1 >= 0 && matrix[row][col - 1] >= matrix[row][col])
                {
                    int new_idx = row * n + col - 1;
                    if(! accessible[new_idx])
        			    new_fringe.push_back(new_idx);
                }
                if(col + 1 < n  && matrix[row][col + 1] >= matrix[row][col])
                {
                    int new_idx = row * n + col + 1;
                    if(! accessible[new_idx])
        			    new_fringe.push_back(new_idx);
                }
            }
            fringe.swap(new_fringe);
        }
    }
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> > & matrix)
    {
        vector<pair<int, int> > result;
        m = matrix.size();
        if(m <= 0)
        {
            return result;
        }
        n = matrix[0].size();
        size = m * n;
        
        bool * pacific_access = new bool[size];
        fill(pacific_access, pacific_access + size, false);
        vector<int> pacific_fringe;
        bool * atlantic_access = new bool[size];
        fill(atlantic_access, atlantic_access + size, false);
        vector<int> atlantic_fringe;
        for(int row = 0; row < m; row ++)
        {
            pacific_fringe.push_back(row * n);
            atlantic_fringe.push_back(row * n + n - 1);
        }
        for(int col = 0; col < n; col ++)
        {
            pacific_fringe.push_back(col);
            atlantic_fringe.push_back((m - 1) * n + col);
        }
        checkFlowTo(matrix, pacific_access, pacific_fringe);
        checkFlowTo(matrix, atlantic_access, atlantic_fringe);
        
        for(int idx = 0; idx < size; idx ++)
        {
            if(pacific_access[idx] && atlantic_access[idx])
            {
                result.push_back(pair<int, int>(idx / n, idx % n));
            }
        }
		delete[] pacific_access;
		delete[] atlantic_access;
        return result;
    }
};
