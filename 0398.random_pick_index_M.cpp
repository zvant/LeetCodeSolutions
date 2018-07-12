/**
 * https://leetcode.com/problems/random-pick-index/description/
 * 2016/10
 * 242 ms
 */

class Solution
{
private:
    unordered_map<int, int> counts;
    vector<int> array;
public:
    Solution(vector<int> nums)
    {
        array = nums;
        for(int idx = 0; idx < nums.size(); idx ++)
        {
            const int & n = nums[idx];
            if(counts.count(n) > 0)
            {
                counts[n] ++;
            }
            else
            {
                counts[n] = 1;
            }
        }
        srand(time(NULL));
    }
    
    int pick(int target)
    {
        int count = counts[target];
        int idx;
        for(idx = 0; idx < array.size(); idx ++)
        {
            if(array[idx] != target)
                continue;
            if(0 == (rand() % count))
            {
                return idx;
            }
            count --;
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
