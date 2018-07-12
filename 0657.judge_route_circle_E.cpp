/**
 * https://leetcode.com/problems/judge-route-circle/description/
 * 2017/08
 * 19 ms
 */

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int len = moves.length();
        int x, y;
        x = y = 0;
        for(int idx = 0; idx < len; idx ++)
        {
            const char & ch = moves[idx];
            if('U' == ch)
            {
                y ++;
            }
            if('D' == ch)
            {
                y --;
            }
            if('R' == ch)
            {
                x ++;
            }
            if('L' == ch)
            {
                x --;
            }
        }
        return (0 == x) && (0 == y);
    }
};
