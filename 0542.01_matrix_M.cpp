/**
 * https://leetcode.com/problems/01-matrix/description/
 * 2017/04
 * 202 ms
 */

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> & matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> result(row, vector<int>(col, -1));
        int count = row * col;
        for(int r = 0; r < row; r ++)
        {
            for(int c = 0; c < col; c ++)
            {
                if(matrix[r][c] == 0)
                {
                    result[r][c] = 0;
                    count --;
                }
            }
        }
        int adjs[4];
        int dist = 0;
        while(count > 0)
        {
            dist ++;
            for(int r = 0; r < row; r ++)
            {
                for(int c = 0; c < col; c ++)
                {
                    if(result[r][c] < 0)
                    {
                        int idx = 0;
                        if( (r > 0 && result[r - 1][c] == dist - 1) ||
                            (r < row - 1 && result[r + 1][c] == dist - 1) ||
                            (c > 0 && result[r][c - 1] == dist - 1) ||
                            (c < col - 1 && result[r][c + 1] == dist - 1)
                        )
                        {
                            result[r][c] = dist;
                            count --;
                        }
                    }
                }
            }
        }
        return result;
    }
};
