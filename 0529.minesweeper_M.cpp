/**
 * https://leetcode.com/problems/minesweeper/description/
 * 2017/03
 * 12 ms
 */

class Solution
{
private:
    int row, col;
    vector<vector<char>> board;
    int countAdjacent(const int x, const int y)
    {
        int count = 0;
        if(x > 0)
        {
            if(y > 0 && board[x - 1][y - 1] == 'M')
                count ++;
            if(board[x - 1][y] == 'M')
                count ++;
            if(y < col - 1 && board[x - 1][y + 1] == 'M')
                count ++;
        }
        if(y > 0 && board[x][y - 1] == 'M')
            count ++;
        if(y < col - 1 && board[x][y + 1] == 'M')
            count ++;
        if(x < row - 1)
        {
            if(y > 0 && board[x + 1][y - 1] == 'M')
                count ++;
            if(board[x + 1][y] == 'M')
                count ++;
            if(y < col - 1 && board[x + 1][y + 1] == 'M')
                count ++;
        }
        return count;
    }
    void clickAt(const int x, const int y)
    {
        if(x < 0 || y < 0 || x >= row || y >= col)
        {
            return;
        }
        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return;
        }
        if(board[x][y] == 'E')
        {
            int count = countAdjacent(x, y);
            if(count == 0)
            {
                board[x][y] = 'B';
                clickAt(x - 1, y - 1);
                clickAt(x - 1, y);
                clickAt(x - 1, y + 1);
                clickAt(x, y - 1);
                clickAt(x, y + 1);
                clickAt(x + 1, y - 1);
                clickAt(x + 1, y);
                clickAt(x + 1, y + 1);
            }
            else
            {
                board[x][y] = '0' + count;
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>> & board, vector<int> & click)
    {
        row = board.size();
        col = board[0].size();
        this -> board = board;
        clickAt(click[0], click[1]);
        return this -> board;
    }
};
