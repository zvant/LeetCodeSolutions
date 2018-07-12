/**
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 * 2017/03
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
    int prev_val;
    int min_diff;
    void inOrderTraverse(TreeNode * root)
    {
        if(NULL != root -> left)
        {
            inOrderTraverse(root -> left);
        }
        if(min_diff > 0)
        {
            int diff = root -> val - prev_val;
            if(diff < min_diff)
            {
                min_diff = diff;
            }
        }
        else
        {
            min_diff = INT_MAX;
        }
        prev_val = root -> val;
        if(NULL != root -> right)
        {
            inOrderTraverse(root -> right);
        }
    }
public:
    int getMinimumDifference(TreeNode * root)
    {
        min_diff = -1;
        inOrderTraverse(root);
        return min_diff;
    }
};
