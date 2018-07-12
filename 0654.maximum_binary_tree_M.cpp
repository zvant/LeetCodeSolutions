/**
 * https://leetcode.com/problems/maximum-binary-tree/description/
 * 2017/08
 * 79 ms
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
    int findMax(const vector<int> & nums, int start, int end)
    {
        int max_idx = start;
        for(int idx = start + 1; idx < end; idx ++)
        {
            if(nums[idx] > nums[max_idx])
            {
                max_idx = idx;
            }
        }
        return max_idx;
    }
    TreeNode * constructTree(const vector<int> & nums, int start, int end)
    {
        if(start >= end)
        {
            return NULL;
        }
        int max_idx = findMax(nums, start, end);
        TreeNode * root = new TreeNode(nums[max_idx]);
        root -> left = constructTree(nums, start, max_idx);
        root -> right = constructTree(nums, max_idx + 1, end);
        return root;
    }
public:
    TreeNode * constructMaximumBinaryTree(vector<int> & nums)
    {
        return constructTree(nums, 0, nums.size());
    }
};
