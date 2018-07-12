/**
 * https://leetcode.com/problems/subsets-ii/description/
 * 2015/08
 * 168 ms
 */

class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> > result;
        result.clear();
        if(nums.size() <= 0)
            return result;
        
        int size = nums.size();
        sort(nums.begin(), nums.end());
        uint64_t min = 0;
        uint64_t max = pow(2, size) - 1;
        vector<uint64_t> masks;
        masks.clear();
        for(int bit = size - 1; bit >= 0; bit --)
            masks.push_back((uint64_t)1 << bit);
        
        for(uint64_t combine = min; combine <= max; combine ++)
        {
            vector<int> sub;
            sub.clear();
            int check;
            for(check = 0; check < size; check ++)
            {
                if(combine == 0)
                    break;
                if((masks[check] & combine) != 0)
                    sub.push_back(nums[check]);
            }
            result.push_back(sub);
        }
        sort(result.begin(), result.end());
        vector<int> sub = result[0];
        for(vector<vector<int> >::iterator it = result.begin() + 1; it != result.end(); )
        {
            if(* it == sub)
            {
                result.erase(it);
            }
            else
            {
                sub = * it;
                it ++;
            }
        }
        return result;
    }
};
