/**
 * https://leetcode.com/problems/trim-a-binary-search-tree/description/
 * 2018/07
 * 12 ms
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
    int low, high;
    
    TreeNode * trim(TreeNode * root)
    {
        if(NULL == root)
        {
            return root;
        }
        if(low > root -> val)
        {
            TreeNode * new_root = root -> right;
            return trim(new_root);
        }
        if(high < root -> val)
        {
            TreeNode * new_root = root -> left;
            return trim(new_root);
        }
        root -> left = trim(root -> left);
        root -> right = trim(root -> right);
        return root;
    }
    
public:
    TreeNode * trimBST(TreeNode * root, int L, int R)
    {
        low = L;
        high = R;
        return trim(root);
    }
};
