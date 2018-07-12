/**
 * https://leetcode.com/problems/flipping-an-image/description/
 * 2018/07
 * 8 ms
 */

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> & A)
    {
        int row = A.size();
        int col = A[0].size();
        for(int r = 0; r < row; r ++)
        {
            int left = 0;
            int right = col - 1;
            while(left < right)
            {
                if(A[r][left] != A[r][right]);
                else
                {
                    A[r][left] = A[r][right] = (0 == A[r][left]) ? 1 : 0;
                }
                left ++;
                right --;
            }
            if(left == right)
            {
                A[r][left] = (0 == A[r][left]) ? 1 : 0;
            }
        }
        return A;
    }
};
