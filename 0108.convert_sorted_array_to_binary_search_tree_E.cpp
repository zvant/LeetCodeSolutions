/**
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 * 2015/08
 * 16 ms
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
    TreeNode * convert(vector<int> & nums, int begin, int end)
    {
        if(end <= begin)
            return NULL;
        int mid = (begin + end) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        if(mid == begin)
            return root;
        root -> left = convert(nums, begin, mid);
        root -> right = convert(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode * sortedArrayToBST(vector<int> & nums)
    {
        int n = nums.size();
        if(n <= 0)
            return NULL;
        
        return convert(nums, 0, n);
    }
};
