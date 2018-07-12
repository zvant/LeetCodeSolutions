/**
 * https://leetcode.com/problems/battleships-in-a-board/description/
 * 2017/02
 * 3 ms
 */

class Solution
{
public:
    int countBattleships(vector<vector<char>> & board)
    {
        int count = 0;
        vector<vector<char>> sea = board;
        int row = sea.size();
        int col = sea[0].size();
        for(int r = 0; r < row; r ++)
        {
            for(int c = 0; c < col; c ++)
            {
                if('X' == sea[r][c])
                {
                    count ++;
                    for(int x = c + 1; x < col; x ++)
                    {
                        if('X' == sea[r][x])
                        {
                            sea[r][x] = '.';
                        }
                        else
                        {
                            break;
                        }
                    }
                    for(int y = r + 1; y < row; y ++)
                    {
                        if('X' == sea[y][c])
                        {
                            sea[y][c] = '.';
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};
