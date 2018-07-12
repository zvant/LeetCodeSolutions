/**
 * https://leetcode.com/problems/toeplitz-matrix/description/
 * 2018/07
 * 8 ms
 */

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> & matrix)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        if(M < 2 || N < 2)
        {
            return true;
        }
        for(int idx = 0; idx < M; idx ++)
        {
            int val = matrix[idx][0];
            for(int shift = 1; shift + idx < M && shift < N; shift ++)
            {
                if(matrix[idx + shift][shift] != val)
                {
                    return false;
                }
            }
        }
        for(int idx = 1; idx < N; idx ++)
        {
            int val = matrix[0][idx];
            for(int shift = 1; shift + idx < N && shift < M; shift ++)
            {
                if(matrix[shift][idx + shift] != val)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
