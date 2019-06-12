/**
 * https://leetcode.com/problems/fibonacci-number/
 * 2019/06
 * 0 ms
 */

class Solution
{
    int * fibs = NULL;
public:
    Solution()
    {
        fibs = new int[31];
        fibs[0] = 0;
        fibs[1] = 1;
        for(int idx = 2; idx < 31; idx ++)
        {
            fibs[idx] = fibs[idx - 1] + fibs[idx - 2];
        }
    }

    int fib(int N)
    {
        return fibs[N];
    }
};
