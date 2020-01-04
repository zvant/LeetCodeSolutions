/**
 * https://leetcode.com/problems/n-queens-ii/
 * 2020/01
 * 4 ms
 */

class Solution
{
private:
    int count;
    
    void place_queen(const int n, vector<pair<int, int>> & queens, int R, bool * col, bool * diag45, bool * diag135)
    {
        if(R >= n)
        {
            count ++;
            return;
        }
        for(int C = 0; C < n; C ++)
        {
            if(col[C] && diag45[R - C + n - 1] && diag135[R + C])
            {
                queens.push_back(pair<int, int>(R, C));
                col[C] = diag45[R - C + n - 1] = diag135[R + C] = false;
                place_queen(n, queens, R + 1, col, diag45, diag135);
                queens.pop_back();
                col[C] = diag45[R - C + n - 1] = diag135[R + C] = true;
            }
        }
    }
public:
    int totalNQueens(int n)
    {
        int n_diags = 2 * n - 1;
        count = 0;
        vector<pair<int, int>> queens;
        bool * col = new bool[n];
        bool * diag45 = new bool[n_diags];
        bool * diag135 = new bool[n_diags];
        fill(col, col + n, true);
        fill(diag45, diag45 + n_diags, true);
        fill(diag135, diag135 + n_diags, true);
        
        place_queen(n, queens, 0, col, diag45, diag135);
        
        delete[] col;
        delete[] diag45;
        delete[] diag135;
        return count;
    }
};
