/**
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 * 2016/09
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
    vector<TreeNode *> nodes;
    void DFS(TreeNode * root)
    {
        if(NULL == root)
            return;
        DFS(root -> left);
        nodes.push_back(root);
        DFS(root -> right);
    }
    
public:
    void recoverTree(TreeNode * root)
    {
        DFS(root);
        int idx1 = 0;
        int idx2 = 0;
        for(int idx = 0; idx < nodes.size() - 1; idx ++)
        {
            if(nodes[idx] -> val > nodes[idx + 1] -> val)
            {
                idx1 = idx;
                break;
            }
        }
        for(int idx = nodes.size() - 1; idx > 0; idx --)
        {
            if(nodes[idx - 1] -> val > nodes[idx] -> val)
            {
                idx2 = idx;
                break;
            }
        }
        int tmp = nodes[idx1] -> val;
        nodes[idx1] -> val = nodes[idx2] -> val;
        nodes[idx2] -> val = tmp;
    }
};
