/**
 * https://leetcode.com/problems/game-of-life/description/
 * 2015/10
 * 4 ms
 */

class Solution
{
private:
    static const int LIVE = 1;
    static const int DIE = 0;
    static const int LIVE_TO_DIE = 10;
    static const int DIE_TO_LIVE = -1;
    int m, n;
    vector<vector<int> > * p_board;
    
    int countLiveNeighbors(int row, int col)
    {
        #define IN_BOARD(x, y) ( \
            ((x) >= 0) && \
            ((x) < m) && \
            ((y) >= 0) && \
            ((y) < n)          )
        
        int count = 0;
        
        if(IN_BOARD(row - 1, col - 1) && (* p_board)[row - 1][col - 1] > 0)
            count ++;
        if(IN_BOARD(row - 1, col) && (* p_board)[row - 1][col] > 0)
            count ++;
        if(IN_BOARD(row - 1, col + 1) && (* p_board)[row - 1][col + 1] > 0)
            count ++;
        
        if(IN_BOARD(row, col - 1) && (* p_board)[row][col - 1] > 0)
            count ++;
        if(IN_BOARD(row, col + 1) && (* p_board)[row][col + 1] > 0)
            count ++;
        
        if(IN_BOARD(row + 1, col - 1) && (* p_board)[row + 1][col - 1] > 0)
            count ++;
        if(IN_BOARD(row + 1, col) && (* p_board)[row + 1][col] > 0)
            count ++;
        if(IN_BOARD(row + 1, col + 1) && (* p_board)[row + 1][col + 1] > 0)
            count ++;
        
        return count;
    }
public:
    void gameOfLife(vector<vector<int> > & board)
    {
        if(((m = board.size()) <= 0) || ((n = board[0].size()) <= 0))
            return;
        p_board = &board;
        
        for(int row = 0; row < m; row ++)
        {
            for(int col = 0; col < n; col ++)
            {
                if(board[row][col] == DIE)
                {
                    if(countLiveNeighbors(row, col) == 3)
                        board[row][col] = DIE_TO_LIVE;
                }
                else
                {
                    int num_live = countLiveNeighbors(row, col);
                    if(num_live < 2 || num_live > 3)
                        board[row][col] = LIVE_TO_DIE;
                }
            }
        }
        
        for(int row = 0; row < m; row ++)
            for(int col = 0; col < n; col ++)
            {
                if(board[row][col] == LIVE_TO_DIE)
                    board[row][col] = 0;
                else if(board[row][col] == DIE_TO_LIVE)
                    board[row][col] = 1;
            }
    }
};
