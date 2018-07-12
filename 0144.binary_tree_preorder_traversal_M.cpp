/**
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 * 2015/07
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
public:
    vector<int> preorderTraversal(TreeNode * root)
    {
        vector<int> seq;
        seq.clear();
        stack<TreeNode *> nodes;
        while(! nodes.empty())
            nodes.pop();
        
        nodes.push(root);
        TreeNode * p_node;
        while(! nodes.empty())
        {
            p_node = nodes.top();
            nodes.pop();
            if(NULL == p_node)
                continue;
            
            seq.push_back(p_node -> val);
            nodes.push(p_node -> right);
            nodes.push(p_node -> left);
        }
        return seq;
    }
};
