/**
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 * 2015/08
 * 8 ms
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
    queue<TreeNode *> nodes;
    void deconstruct(TreeNode * root)
    {
        if(root == NULL)
            return;
        nodes.push(root);
        deconstruct(root -> left);
        deconstruct(root -> right);
    }
public:
    void flatten(TreeNode * root)
    {
        while(! nodes.empty())
            nodes.pop();
        deconstruct(root);
        if(nodes.empty())
            return;
        
        TreeNode * ptr = nodes.front();
        nodes.pop();
        
        while(! nodes.empty())
        {
            ptr -> right = nodes.front();
            ptr -> left = NULL;
            ptr = ptr -> right;
            nodes.pop();
        }
        ptr -> left = NULL;
        ptr -> right = NULL;
    }
};
