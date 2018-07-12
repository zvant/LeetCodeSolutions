/**
 * https://leetcode.com/problems/transpose-matrix/description/
 * 2018/07
 * 16 ms
 */

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> & A)
    {
        vector<vector<int>> AT;
        int row = A.size();
        // if(row < 1)
        // {
        //     return AT;
        // }
        int col = A[0].size();
        // if(col < 1)
        // {
        //     return AT;
        // }
        AT.resize(col);
        for(int c = 0; c < col; c ++)
        {
            AT[c].resize(row);
            for(int r = 0; r < row; r ++)
            {
                AT[c][r] = A[r][c];
            }
        }
        return AT;
    }
};
