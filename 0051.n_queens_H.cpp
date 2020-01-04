/**
 * https://leetcode.com/problems/n-queens/
 * 2020/01
 * 4 ms
 */

class Solution
{
private:
    char * board = nullptr;
    vector<vector<string>> all_configs;
    
    void place_queen(const int n, vector<pair<int, int>> & queens, int R, bool * col, bool * diag45, bool * diag135)
    {
        if(R >= n)
        {
            all_configs.push_back(vector<string>());
            for(int i = 0; i < n * n; i ++)
            {
                board[i] = '.';
            }
            for(auto it = queens.begin(); it != queens.end(); it ++)
            {
                board[(it -> first) * n + it -> second] = 'Q';
            }
            for(int R_board = 0; R_board < n; R_board ++)
            {
                all_configs.back().push_back(string(board + R_board * n, n));
            }
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
    vector<vector<string>> solveNQueens(int n)
    {
        int n_diags = 2 * n - 1;
        board = new char[n * n];
        vector<pair<int, int>> queens;
        bool * col = new bool[n];
        bool * diag45 = new bool[n_diags];
        bool * diag135 = new bool[n_diags];
        fill(col, col + n, true);
        fill(diag45, diag45 + n_diags, true);
        fill(diag135, diag135 + n_diags, true);
        
        place_queen(n, queens, 0, col, diag45, diag135);
        
        delete[] board;
        delete[] col;
        delete[] diag45;
        delete[] diag135;
        return all_configs;
    }
};
