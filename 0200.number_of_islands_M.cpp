/**
 * https://leetcode.com/problems/number-of-islands/description/
 * 2017/02
 * 9 ms
 */

class Solution
{
private:
    struct Coordinate
    {
        int x, y;
        Coordinate(int x_, int y_) : x(x_), y(y_) {}
    };
public:
    int numIslands(vector<vector<char>> & grid)
    {
        int row = grid.size();
        if(row < 1)
        {
            return 0;
        }
        int col = grid[0].size();
        queue<Coordinate> coords;
        int count = 0;
        for(int r = 0; r < row; r ++)
        {
            for(int c = 0; c < col; c ++)
            {
                if('0' == grid[r][c])
                {
                    continue;
                }
                count ++;
                coords.push(Coordinate(r, c));
                while(! coords.empty())
                {
                    int x = coords.front().x;
                    int y = coords.front().y;
                    coords.pop();
                    if(x > 0) // up
                    {
                        if('1' == grid[x - 1][y])
                        {
                            coords.push(Coordinate(x - 1, y));
                        }
                        grid[x - 1][y] = '0';
                    }
                    if(x < row - 1) // down
                    {
                        if('1' == grid[x + 1][y])
                        {
                            coords.push(Coordinate(x + 1, y));
                        }
                        grid[x + 1][y] = '0';
                    }
                    if(y > 0) // left
                    {
                        if('1' == grid[x][y - 1])
                        {
                            coords.push(Coordinate(x, y - 1));
                        }
                        grid[x][y - 1] = '0';
                    }
                    if(y < col - 1) // right
                    {
                        if('1' == grid[x][y + 1])
                        {
                            coords.push(Coordinate(x, y + 1));
                        }
                        grid[x][y + 1] = '0';
                    }
                }
            }
        }
        return count;
    }
};
