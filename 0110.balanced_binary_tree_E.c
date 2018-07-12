/**
 * https://leetcode.com/problems/balanced-binary-tree/description/
 * 2015/07
 * 8 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth(struct TreeNode * root, int dep)
{
    if(root == NULL)
        return dep;
    int d1 = depth(root -> left, dep + 1);
    int d2 = depth(root -> right, dep + 1);
    return (d1 > d2) ? d1 : d2;
}

bool isBalanced(struct TreeNode * root)
{
    if(root == NULL)
        return true;
    else
        return abs(depth(root -> left, 1) - depth(root -> right, 1)) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
}
