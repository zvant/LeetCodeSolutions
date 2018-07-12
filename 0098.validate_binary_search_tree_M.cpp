/**
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 * 2015/08
 * 16 ms
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
    vector<int> in_order_seq;
    void inOrderTraverse(TreeNode * root)
    {
        if(NULL == root)
            return;
        inOrderTraverse(root -> left);
        in_order_seq.push_back(root -> val);
        inOrderTraverse(root -> right);
    }
public:
    bool isValidBST(TreeNode * root)
    {
        in_order_seq.clear();
        inOrderTraverse(root);
        int n = in_order_seq.size();
        if(n <= 1)
            return true;
        for(int idx = 0; idx < n - 1; idx ++)
            if(in_order_seq[idx + 1] <= in_order_seq[idx])
                return false;
        return true;
    }
};
