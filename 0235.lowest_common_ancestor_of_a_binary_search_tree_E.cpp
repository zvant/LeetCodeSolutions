/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 * 2015/09
 * 40 ms
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
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
    {
        if(p == NULL || q == NULL || root == NULL)
            return NULL;
        
        TreeNode * node = root;
        
        while(node != NULL)
        {
            if(node == p || node == q)
                break;
            if(node -> val < p -> val && node -> val < q -> val)
                node = node -> right;
            else if(node -> val > p -> val && node -> val > q -> val)
                node = node -> left;
            else
                break;
        }
        return node;
    }
};
