/**
 * https://leetcode.com/problems/permutations-ii/description/
 * 2015/08
 * 36 ms
 */

class Solution
{
private:
    int n;
    vector<vector<int> > permutations;
    void nextPermutation(vector<int> & nums)
    {
        int idx = n - 1;
        while(idx > 0)
        {
            if(nums[idx] > nums[idx - 1])
                break;
            idx --;
        }
        if(idx == 0)
            reverse(nums.begin(), nums.end());
        else
        {
            sort(nums.begin() + idx, nums.end());
            int next;
            for(next = idx; next < nums.size(); next ++)
                if(nums[next] > nums[idx - 1])
                    break;
            int tmp = nums[next];
            nums[next] = nums[idx - 1];
            nums[idx - 1] = tmp;
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> & nums)
    {
        permutations.clear();
        n = nums.size();
        if(n <= 0)
            return permutations;
        if(n <= 1)
        {
            permutations.push_back(nums);
            return permutations;
        }
        sort(nums.begin(), nums.end());
        permutations.push_back(nums);
        vector<int> next = nums;
        while(true)
        {
            nextPermutation(next);
            if(next == permutations[0])
                break;
            else
                permutations.push_back(next);
        }
        return permutations;
    }
};
