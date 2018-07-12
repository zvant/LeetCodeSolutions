/**
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 * 2017/04
 * 6 ms
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
    int max_len;
    int maxDepth(TreeNode * root)
    {
        if(NULL == root)
        {
            return 0;
        }
        int left_depth = maxDepth(root -> left);
        int right_depth = maxDepth(root -> right);
        int len = left_depth + right_depth;
        max_len = max(len, max_len);
        return 1 + max(left_depth, right_depth);
    }
public:
    int diameterOfBinaryTree(TreeNode * root)
    {
        max_len = 0;
        maxDepth(root);
        return max_len;
    }
};
