/**
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 * 2017/06
 * 132 ms
 */

class Solution
{
public:
    int findLHS(vector<int> & nums)
    {
        int size = nums.size();
        if(size < 1)
        {
            return 0;
        }
        map<int, int> counts;
        for(int idx = 0; idx < size; idx ++)
        {
            const int & i = nums[idx];
            if(counts.find(i) != counts.end())
            {
                counts[i] ++;
            }
            else
            {
                counts[i] = 1;
            }
        }
        // sort(counts.begin(), counts.end());
        int len = 0;
        auto last_it = counts.end();
        last_it --;
        for(auto it = counts.begin(); it != last_it; )
        {
            int key1 = it -> first;
            int count1 = it -> second;
            it ++;
            if(key1 + 1 == it -> first)
            {
                len = max(len, it -> second + count1);
            }
        }
        return len;
    }
};
