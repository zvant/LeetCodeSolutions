/**
 * https://leetcode.com/problems/teemo-attacking/description/
 * 2017/02
 * 73 ms
 */

class Solution
{
public:
    int findPoisonedDuration(vector<int> & timeSeries, int duration)
    {
        int size = timeSeries.size();
        int total = 0;
        if(size < 1 || duration < 1)
        {
            return total;
        }
        total += duration;
        for(int idx = 0; idx < size - 1; idx ++)
        {
            int diff = timeSeries[idx + 1] - timeSeries[idx];
            if(diff >= duration)
            {
                total += duration;
            }
            else
            {
                total += diff;
            }
        }
        return total;
    }
};
