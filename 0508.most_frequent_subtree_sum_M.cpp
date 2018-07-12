/**
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 * 2017/02
 * 15 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    struct TwoInt
    {
        int i1, i2;
        bool operator<(const TwoInt & n) const
        {
            return i1 < n.i1;
        }
    };
    
    unordered_map<int, int> counts;
    
    int calculateSum(TreeNode * root)
    {
        int left_sum = (NULL == root -> left) ? 0 : calculateSum(root -> left);
        int right_sum = (NULL == root -> right) ? 0 : calculateSum(root -> right);
        int sum = root -> val + left_sum + right_sum;
        if(counts.count(sum) < 1)
        {
            counts[sum] = 1;
        }
        else
        {
            counts[sum] ++;
        }
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode * root)
    {
        vector<int> modes;
        if(NULL == root)
        {
            return modes;
        }
        calculateSum(root);
        int size = counts.size();
        TwoInt * nums = new TwoInt[size];
        TwoInt * ptr = nums;
        for(auto it = counts.begin(); it != counts.end(); it ++)
        {
            ptr -> i1 = it -> second;
            ptr -> i2 = it -> first;
            ptr ++;
        }
        sort(nums, nums + size);
        int max_freq = nums[size - 1].i1;
        for(int idx = size - 1; idx >= 0; idx --)
        {
            if(nums[idx].i1 < max_freq)
            {
                break;
            }
            modes.push_back(nums[idx].i2);
        }
        delete[] nums;
        return modes;
    }
};
