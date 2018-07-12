/**
 * https://leetcode.com/problems/summary-ranges/description/
 * 2015/07
 * 0 ms
 */

#include <cstdlib>

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> ranges;
        ranges.clear();
        if(nums.size() <= 0)
            return ranges;
        
        int first, last;
        int idx = 0;
        while(idx < nums.size())
        {
            first = nums[idx];
            last = first;
            idx ++;
            while(nums[idx] == last + 1 && idx < nums.size())
            {
                last = nums[idx];
                idx ++;
            }
            char buff[128];
            memset(buff, 0, 128);
            if(last == first)
            {
                sprintf(buff, "%d", first);
                string r(buff);
                ranges.push_back(r);
            }
            else
            {
                sprintf(buff, "%d", first);
                string r(buff);
                r.append("->");
                memset(buff, 0, 128);
                sprintf(buff, "%d", last);
                r.append(buff);
                ranges.push_back(r);
            }
        }
        return ranges;
    }
};
