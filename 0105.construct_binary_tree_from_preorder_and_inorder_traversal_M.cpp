/**
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 * 2015/09
 * 56 ms
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
    int size;
    vector<int> * pre_seq;
    vector<int> * in_seq;
    TreeNode * constructTree(int pre_begin, int in_begin, int size)
    {
        if(size <= 0)
            return NULL;
        
        TreeNode * tree = new TreeNode((* pre_seq)[pre_begin]);
        if(size == 1)
            return tree;
        int inorder_root_idx = find( \
                in_seq -> begin() + in_begin, \
                in_seq -> begin() + in_begin + size, \
                (* pre_seq)[pre_begin] \
            ) - (in_seq -> begin());
        tree -> left = constructTree( \
            pre_begin + 1, \
            in_begin, \
            inorder_root_idx - in_begin);
        tree -> right = constructTree( \
            pre_begin + 1 + inorder_root_idx - in_begin, \
            inorder_root_idx + 1, \
            size - 1 - (inorder_root_idx - in_begin));
        return tree;
    }
public:
    TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder)
    {
        if((size = preorder.size()) <= 0 || (inorder.size() != size))
            return NULL;
        
        pre_seq = &preorder;
        in_seq = &inorder;
        return constructTree(0, 0, size);
    }
};
