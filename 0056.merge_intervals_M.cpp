/**
 * https://leetcode.com/problems/merge-intervals/
 * 2020/01
 * 20 ms
 */

bool comp(const vector<int> & i1, const vector<int> & i2)
{
    return i1[0] < i2[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 0; i < intervals.size(); i ++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
            while(i < intervals.size() - 1 && right >= intervals[i + 1][0])
            {
                right = max(right, intervals[i + 1][1]);
                i ++;
            }
            if(intervals.size() - 1 == i)
            {
                if(right < intervals[i][0])
                {
                    merged.push_back(intervals[i]);
                }
            }
            merged.push_back(vector<int>({left, right}));
        }
        return merged;
    }
};
