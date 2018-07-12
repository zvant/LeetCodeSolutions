/**
 * https://leetcode.com/problems/student-attendance-record-ii/description/
 * 2017/05
 * 26 ms
 */

class Solution
{
private:
    const static int MOD = 1000000007;
    int g[3];
    int f[3];
    int last_n;
public:
    Solution()
    {
        g[0] = 2; g[1] = 4; g[2] = 7;
        f[0] = 3; f[1] = 8; f[2] = 19;
        last_n = 3;
    }
    int checkRecord(int n)
    {
        // f_n : L/P/A
        // g_n : L/P
        // f_n = g_n   + f_n-1 + f_n-2 + f_n-3
        // g_n = g_n-1 + g_n-2 + g_n-3
        if(n <= last_n)
        {
            if(n >= last_n - 2)
            {
                return f[2 - last_n + n];
            }
            else
            {
                Solution();
            }
        }
        while(last_n < n)
        {
            int gk1 = ((g[0] + g[1]) % MOD + g[2]) % MOD;
            g[0] = g[1]; g[1] = g[2]; g[2] = gk1;
            int fk1 = (((f[0] + f[1]) % MOD + f[2]) % MOD + gk1) % MOD;
            f[0] = f[1]; f[1] = f[2]; f[2] = fk1;
            last_n ++;
        }
        return f[2];
    }
};
