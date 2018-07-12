/**
 * https://leetcode.com/problems/minimum-time-difference/description/
 * 2017/03
 * 19 ms
 */

class Solution {
public:
    int findMinDifference(vector<string> & timePoints)
    {
        int size = timePoints.size();
        vector<int> time_min;
        time_min.resize(size);
        for(int idx = 0; idx < size; idx ++)
        {
            const string & t = timePoints[idx];
            time_min[idx] = 60 * (10 * (t[0] - '0') + t[1] - '0') + 10 * (t[3] - '0') + t[4] - '0';
        }
        sort(time_min.begin(), time_min.end());
        int min_diff = time_min[0] + 1440 - time_min[size - 1];
        for(int idx = 1; idx < size; idx ++)
        {
            min_diff = min(min_diff, time_min[idx] - time_min[idx - 1]);
        }
        return min_diff;
    }
};
