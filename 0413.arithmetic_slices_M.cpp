/**
 * https://leetcode.com/problems/arithmetic-slices/description/
 * 2017/02
 * 3 ms
 */

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> & A)
    {
        int n = A.size();
        int count = 0;
        for(int p = 0; p < n - 2; )
        {
            int incr = A[p + 1] - A[p];
            int q = p + 2;
            while(q < n && incr == A[q] - A[q - 1])
            {
                q ++;
            }
            int len = q - p;
            count += (len - 2) * (len - 1) / 2;
            p = q - 1;
        }
        return count;
    }
};
