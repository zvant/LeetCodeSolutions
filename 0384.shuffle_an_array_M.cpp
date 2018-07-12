/**
 * https://leetcode.com/problems/shuffle-an-array/description/
 * 2016/08
 * 368 ms
 */

class Solution
{
private:
    vector<int> num_array;
public:
    Solution(vector<int> nums) : num_array(nums) { }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return num_array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> result(num_array);
        random_shuffle(result.begin(), result.end());
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
