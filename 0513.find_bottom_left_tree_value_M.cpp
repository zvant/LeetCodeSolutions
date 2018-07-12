/**
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 * 2017/03
 * 9 ms
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
    int bottom_left;
    int bottom_level;
    void traverse(TreeNode * root, int level)
    {
        if(level >= bottom_level)
        {
            bottom_left = root -> val;
            bottom_level = level;
        }
        if(NULL != root -> right)
        {
            traverse(root -> right, level + 1);
        }
        if(NULL != root -> left)
        {
            traverse(root -> left, level + 1);
        }
    }
public:
    int findBottomLeftValue(TreeNode * root)
    {
        bottom_level = -1;
        traverse(root, 0);
        return bottom_left;
    }
};
