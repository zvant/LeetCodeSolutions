/**
 * https://leetcode.com/problems/symmetric-tree/description/
 * 2015/08
 * 4 ms
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
    void reverse(TreeNode * root)
    {
        if(NULL == root)
            return;
        TreeNode * tmp;
        tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
        reverse(root -> left);
        reverse(root -> right);
    }
    bool isSame(TreeNode * t1, TreeNode * t2)
    {
        if(t1 == NULL || t2 == NULL)
            return (t1 == t2);
        
        if(t1 -> val != t2 -> val)
            return false;
        return isSame(t1 -> left, t2 -> left) && isSame(t1 -> right, t2 -> right);
    }
public:
    bool isSymmetric(TreeNode * root)
    {
        if(NULL == root)
            return true;
        reverse(root -> right);
        return isSame(root -> left, root -> right);
    }
};
