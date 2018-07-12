/**
 * https://leetcode.com/problems/diagonal-traverse/description/
 * 2017/02
 * 82 ms
 */

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> & matrix)
    {
        vector<int> nums;
        int M = matrix.size();
        if(M < 1)
        {
            return nums;
        }
        int N = matrix[0].size();
        int size = M * N;
        nums.resize(size);
        int idx = 0;
        int x = 0;
        int y = 0;
        int step = 1;
        while(idx < size)
        {
            if(step > 0)
            {
                while(x >= 0 && y < N)
                {
                    nums[idx ++] = matrix[x][y];
                    x --;
                    y ++;
                }
                x ++;
                if(y == N)
                {
                    x ++;
                    y --;
                }
                step = -1;
            }
            else
            {
                while(y >= 0 && x < M)
                {
                    nums[idx ++] = matrix[x][y];
                    x ++;
                    y --;
                }
                y ++;
                if(x == M)
                {
                    x --;
                    y ++;
                }
                step = 1;
            }
        }
        return nums;
    }
};
