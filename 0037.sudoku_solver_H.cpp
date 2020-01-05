/**
 * https://leetcode.com/problems/sudoku-solver/
 * 2020/01
 * 8 ms
 */

class Solution
{
private:
    int * cols, * rows, * sqrs;
    stack<pair<int, int>> vaccs;

    bool solver(vector<vector<char>> & board)
    {
        if(vaccs.empty())
        {
            return true;
        }
        int r = vaccs.top().first;
        int c = vaccs.top().second;
        vaccs.pop();
        for(int n = 1; n <= 9; n ++)
        {
            int mask = 1 << n;
            if(0 == (rows[r] & mask) && 0 == (cols[c] & mask) && 0 == (sqrs[(r / 3) * 3 + c / 3] & mask))
            {
                board[r][c] = n + '0';
                rows[r] |= mask;
                cols[c] |= mask;
                sqrs[(r / 3) * 3 + c / 3] |= mask;
                
                if(solver(board))
                {
                    return true;
                }
                else
                {
                    board[r][c] = '.';
                    rows[r] &= ~ mask;
                    cols[c] &= ~ mask;
                    sqrs[(r / 3) * 3 + c / 3] &= ~ mask;
                }
            }
        }
        vaccs.push(pair<int, int>(r, c));
        return false;
    }
public:
    void solveSudoku(vector<vector<char>> & board)
    {
        cols = new int[27];
        rows = cols + 9;
        sqrs = cols + 18;
        fill(cols, cols + 27, 0);
        
        for(int r = 0; r < 9; r ++)
        {
            for(int c = 0; c < 9; c ++)
            {
                if(board[r][c] != '.')
                {
                    int n = 1 << (board[r][c] - '0');
                    rows[r] |= n;
                    cols[c] |= n;
                    sqrs[(r / 3) * 3 + c / 3] |= n;
                }
                else
                {
                    vaccs.push(pair<int, int>(r, c));
                }
            }
        }
        
        solver(board);        
        delete[] cols;
    }
};
