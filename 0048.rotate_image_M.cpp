/**
 * https://leetcode.com/problems/rotate-image/description/
 * 2015/08
 * 4 ms
 */

class Solution
{
public:
    void rotate(vector<vector<int> > & matrix)
    {
        if(matrix.size() <= 0 || matrix.size() != matrix[0].size())
            return;
        int n = matrix.size();
        if(n <= 1)
            return;
        
        for(int layer = 0; layer < n / 2; layer ++)
        {
            for(int idx = 0; idx < n - layer * 2 - 1; idx ++)
            {
                int tmp = matrix[layer][layer + idx];
                matrix[layer][layer + idx] = matrix[n - 1 - layer - idx][layer];
                matrix[n - 1 - layer - idx][layer] = matrix[n - 1 - layer][n - 1 - layer - idx];
                matrix[n - 1 - layer][n - 1 - layer - idx] = matrix[layer + idx][n - 1 - layer];
                matrix[layer + idx][n - 1 - layer] = tmp;
            }
        }
    }
};
