/**
 * https://leetcode.com/problems/hamming-distance/description/
 * 2017/01
 * 3 ms
 */

class Solution
{
private:
    int bits = sizeof(int) * CHAR_BIT;
public:
    int hammingDistance(int x, int y)
    {
        int dist = 0;
        int x_y = x ^ y;
        for(int idx = 0; idx < bits; idx ++)
        {
            dist += 1 & x_y;
            x_y >>= 1;
        }
        return dist;
    }
};
