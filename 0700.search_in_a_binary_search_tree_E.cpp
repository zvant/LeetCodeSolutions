/**
 * https://leetcode.com/problems/search-in-a-binary-search-tree/
 * 2019/06
 * 52 ms
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
public:
    TreeNode * searchBST(TreeNode * root, int val)
    {
        if(NULL == root || root -> val == val)
        {
            return root;
        }
        if(root -> val > val)
        {
            return searchBST(root -> left, val);
        }
        else
        {
            return searchBST(root -> right, val);
        }
    }
};