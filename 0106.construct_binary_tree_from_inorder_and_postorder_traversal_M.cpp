/**
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
    vector<int> * post_seq;
    vector<int> * in_seq;
    TreeNode * constructTree(int in_begin, int post_end, int size)
    {
        if(size <= 0)
            return NULL;
        
        TreeNode * tree = new TreeNode((* post_seq)[post_end]);
        if(size == 1)
            return tree;
        int inorder_root_idx = find( \
                in_seq -> begin() + in_begin, \
                in_seq -> begin() + in_begin + size, \
                (* post_seq)[post_end] \
            ) - (in_seq -> begin());
        tree -> left = constructTree( \
            in_begin, \
            post_end - size + inorder_root_idx - in_begin, \
            inorder_root_idx - in_begin);
        tree -> right = constructTree( \
            inorder_root_idx + 1, \
            post_end - 1, \
            size - 1 - (inorder_root_idx - in_begin));
        return tree;
    }
public:
    TreeNode * buildTree(vector<int> & inorder, vector<int> & postorder)
    {
        if((size = inorder.size()) <= 0 || (postorder.size() != size))
            return NULL;
        
        in_seq = &inorder;
        post_seq = &postorder;
        
        return constructTree(0, size - 1, size);
    }
};
