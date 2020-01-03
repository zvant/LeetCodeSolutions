/**
 * https://leetcode.com/problems/insert-interval/
 * 2020/01
 * 12 ms
 */

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if(intervals.size() < 1)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<int> starts;
        for(int i = 0; i < intervals.size(); i ++)
        {
            starts.push_back(intervals[i][0]);
        }
        int i2 = upper_bound(starts.begin(), starts.end(), newInterval[1]) - starts.begin();
        int i1 = upper_bound(starts.begin(), starts.begin() + i2, newInterval[0]) - starts.begin();
        if(i1 > 0 && intervals[i1 - 1][1] >= newInterval[0])
        {
            newInterval[0] = intervals[i1 - 1][0];
            i1 --;
        }
        if(i2 > 0)
        {
            newInterval[1] = max(newInterval[1], intervals[i2 - 1][1]);
        }
        intervals.erase(intervals.begin() + i1, intervals.begin() + i2);
        intervals.insert(intervals.begin() + i1, newInterval);
        return intervals;
    }
};
