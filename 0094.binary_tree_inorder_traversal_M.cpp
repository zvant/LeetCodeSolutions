/**
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 * 2015/08
 * 0 ms
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
    vector<int> seq;
    stack<TreeNode *> l_nodes;
    stack<TreeNode *> r_nodes;
    stack<int> nodes;
public:
    vector<int> inorderTraversal(TreeNode * root)
    {
        seq.clear();
        while(! nodes.empty())
            nodes.pop();
        while(! l_nodes.empty())
            l_nodes.pop();
        while(! r_nodes.empty())
            r_nodes.pop();
        if(NULL == root)
            return seq;
        
        nodes.push(root -> val);
        l_nodes.push(root -> left);
        r_nodes.push(root -> right);
        while(! (nodes.empty() && l_nodes.empty() && r_nodes.empty()))
        {
            while(! l_nodes.empty())
            {
                TreeNode * n = l_nodes.top();
                l_nodes.pop();
                if(n != NULL)
                {
                    if(n -> left == NULL && n -> right == NULL)
                        seq.push_back(n -> val);
                    else
                    {
                        nodes.push(n -> val);
                        l_nodes.push(n -> left);
                        r_nodes.push(n -> right);
                    }
                }
            }
            if(! nodes.empty())
            {
                seq.push_back(nodes.top());
                nodes.pop();
            }
            if(! r_nodes.empty())
            {
                TreeNode * n = r_nodes.top();
                r_nodes.pop();
                if(n != NULL)
                {
                    if(n -> left == NULL && n -> right == NULL)
                        seq.push_back(n -> val);
                    else
                    {
                        nodes.push(n -> val);
                        l_nodes.push(n -> left);
                        r_nodes.push(n -> right);
                    }
                }
            }
        }
        return seq;
    }
};
