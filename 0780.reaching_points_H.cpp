/**
 * https://leetcode.com/problems/reaching-points/
 * 2019/11
 * 4 ms
 */

class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while(tx > sx && ty > sy)
        {
            if(tx > ty)
            {
                tx %= ty;
            }
            else
            {
                ty %= tx;
            }
        }
        if(tx == sx && ty >= sy)
        {
            return (ty - sy) % tx == 0;
        }
        if(ty == sy && tx >= sx)
        {
            return (tx - sx) % ty == 0;
        }
        return false;
    }
};
