/**
 * https://leetcode.com/problems/invert-binary-tree/description/
 * 2015/07
 * 0 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(NULL == root)
        return NULL;
    struct TreeNode * tmp = root -> left;
    root -> left = root -> right;
    root -> right = tmp;
    invertTree(root -> left);
    invertTree(root -> right);
    return root;
}
