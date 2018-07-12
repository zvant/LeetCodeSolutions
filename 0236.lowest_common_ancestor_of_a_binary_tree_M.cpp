/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 * 2015/09
 * 24 ms
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
    vector<vector<TreeNode *> > paths;
    
    bool findPathTo(TreeNode * node, TreeNode * ptr, vector<TreeNode *> & path)
    {
        if(node == NULL || ptr == NULL)
            return false;
        
        path.push_back(node);
        int reserve_size = path.size();
        
        if(node == ptr)
            return true;
        
        if(findPathTo(node -> left, ptr, path))
            return true;
        else
        {
            path.resize(reserve_size);
            return findPathTo(node -> right, ptr, path);
        }
    }
public:
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
    {
        if(p == NULL || q == NULL || root == NULL)
            return NULL;
        
        paths.resize(2);
        paths[0].clear();
        paths[1].clear();
        
        if(! (findPathTo(root, p, paths[0]) && findPathTo(root, q, paths[1])))
            return NULL;
        
        int size_p = paths[0].size();
        int size_q = paths[1].size();
        for(int idx = ((size_p < size_q) ? size_p : size_q) - 1; idx >= 0; idx --)
            if(paths[0][idx] == paths[1][idx])
                return paths[0][idx];
        
        return NULL;
    }
};
