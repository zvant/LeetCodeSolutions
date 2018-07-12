/**
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 * 2018/07
 * 0 ms
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
    int prev_val, min_diff;
    void traverse(TreeNode * root)
    {
        if(NULL == root)
        {
            return;
        }
        traverse(root -> left);
        min_diff = min(min_diff, root -> val - prev_val);
        prev_val = root -> val;
        traverse(root -> right);
    }
public:
    int minDiffInBST(TreeNode * root)
    {
        prev_val = -10000;
        min_diff = INT_MAX;
        traverse(root);
        return min_diff;
    }
};
