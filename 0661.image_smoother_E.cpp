/**
 * https://leetcode.com/problems/image-smoother/description/
 * 2017/09
 * 176 ms
 */

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M)
    {
        int R = M.size();
        int C = M[0].size();
        vector<vector<int>> smoothed(M);
        if(R > 1 && C > 1)
        {
            smoothed[0][0] = (M[0][0] + M[0][1] + M[1][0] + M[1][1]) / 4;
            smoothed[0][C - 1] = (M[0][C - 1] + M[0][C - 2] + M[1][C - 1] + M[1][C - 2]) / 4;
            smoothed[R - 1][0] = (M[R - 1][0] + M[R - 1][1] + M[R - 2][0] + M[R - 2][1]) / 4;
            smoothed[R - 1][C - 1] = (M[R - 1][C - 1] + M[R - 1][C - 2] + M[R - 2][C - 1] + M[R - 2][C - 2]) / 4;
            for(int col = 1; col < C - 1; col ++)
            {
                smoothed[0][col] = (M[0][col - 1] + M[0][col] + M[0][col + 1] +
                                    M[1][col - 1] + M[1][col] + M[1][col + 1]) / 6;
                smoothed[R - 1][col] = (M[R - 1][col - 1] + M[R - 1][col] + M[R - 1][col + 1] +
                                        M[R - 2][col - 1] + M[R - 2][col] + M[R - 2][col + 1]) / 6;
            }
            for(int row = 1; row < R - 1; row ++)
            {
                smoothed[row][0] = (M[row - 1][0] + M[row][0] + M[row + 1][0] +
                                    M[row - 1][1] + M[row][1] + M[row + 1][1]) / 6;
                smoothed[row][C - 1] = (M[row - 1][C - 1] + M[row][C - 1] + M[row + 1][C - 1] +
                                        M[row - 1][C - 2] + M[row][C - 2] + M[row + 1][C - 2]) / 6;
            }
            for(int row = 1; row < R - 1; row ++)
            {
                for(int col = 1; col < C - 1; col ++)
                {
                    smoothed[row][col] = (
                        M[row - 1][col - 1] + M[row - 1][col] + M[row - 1][col + 1] +
                        M[row][col - 1] + M[row][col] + M[row][col + 1] +
                        M[row + 1][col - 1] + M[row + 1][col] + M[row + 1][col + 1]) / 9;
                }
            }
        }
        else
        {
            if(R > 1)
            {
                smoothed[0][0] = (M[0][0] + M[1][0]) / 2;
                smoothed[R - 1][0] = (M[R - 1][0] + M[R - 2][0]) / 2;
                for(int row = 1; row < R - 1; row ++)
                {
                    smoothed[row][0] = (M[row - 1][0] + M[row][0] + M[row + 1][0]) / 3;
                }
            }
            if(C > 1)
            {
                smoothed[0][0] = (M[0][0] + M[0][1]) / 2;
                smoothed[0][C - 1] = (M[0][C - 1] + M[0][C - 2]) / 2;
                for(int col = 1; col < C - 1; col ++)
                {
                    smoothed[0][col] = (M[0][col - 1] + M[0][col] + M[0][col + 1]) / 3;
                }
            }
        }
        return smoothed;
    }
};
