/**
 * https://leetcode.com/problems/valid-sudoku/description/
 * 2015/08
 * 12 ms
 */

class Solution
{
private:
    bool checkRactangle(const vector<vector<char> > & board, int x1, int x2, int y1, int y2)
    {
        int nums[9] = {0};
        for(int x = x1; x < x2; x ++)
            for(int y = y1; y < y2; y ++)
            {
                if(board[x][y] != '.')
                {
                    if((nums[board[x][y] - '1']) > 0)
                        return false;
                    nums[board[x][y] - '1'] ++;
                }
            }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char> > & board)
    {
        if(board.size() != 9 || board[0].size() != 9)
            return false;
        for(int row = 0; row < 9; row ++)
            if(false == checkRactangle(board, 0, 9, row, row + 1))
                return false;
        for(int col = 0; col < 9; col ++)
            if(false == checkRactangle(board, col, col + 1, 0, 9))
                return false;
        for(int row = 0; row < 9; row += 3)
            for(int col = 0; col < 9; col += 3)
            {
                if(false == checkRactangle(board, col, col + 3, row, row + 3))
                    return false;
            }
        return true;
    }
};
