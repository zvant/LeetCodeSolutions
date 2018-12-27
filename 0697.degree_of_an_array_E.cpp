/**
 * https://leetcode.com/problems/degree-of-an-array/
 * 2018/12
 * 104 ms
 */

class Solution
{
private:
    int findSubArray(int e, const vector<int> & nums)
    {
        int l_idx, r_idx;
        for(l_idx = 0; l_idx < nums.size(); l_idx ++)
        {
            if(e == nums[l_idx])
            {
                break;
            }
        }
        for(r_idx = nums.size() - 1; r_idx >= 0; r_idx --)
        {
            if(e == nums[r_idx])
            {
                break;
            }
        }
        return r_idx - l_idx + 1;
    }
    
public:
    int findShortestSubArray(vector<int>& nums)
    {
        unordered_map<int, int> freqs;
        for(auto it = nums.begin(); it != nums.end(); it ++)
        {
            if(freqs.count(* it) < 1)
            {
                freqs[* it] = 1;
            }
            else
            {
                freqs[* it] += 1;
            }
        }
        
        int max_freq = -1;
        for(auto it = freqs.begin(); it != freqs.end(); it ++)
        {
            if(it -> second > max_freq)
            {
                max_freq = it -> second;
            }
        }
        
        int min_len = nums.size();
        for(auto it = freqs.begin(); it != freqs.end(); it ++)
        {
            if(max_freq == it -> second)
            {
                min_len = min(min_len, findSubArray(it -> first, nums));
            }
        }
        return min_len;
    }
};
