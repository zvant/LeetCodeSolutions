/**
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 * 2015/08
 * 44 ms
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution
{
private:
    vector<vector<TreeLinkNode *> > layers;
    int depth;
    void traverse(TreeLinkNode * root, int dep)
    {
        if(NULL == root)
            return;
        if(dep + 1 > layers.size())
        {
            depth ++;
            vector<TreeLinkNode *> l;
            l.clear();
            layers.push_back(l);
        }
        layers[dep].push_back(root);
        traverse(root -> left, dep + 1);
        traverse(root -> right, dep + 1);
    }
    void populate() const
    {
        for(int dep = 0; dep < layers.size(); dep ++)
            for(int idx = 0; idx < layers[dep].size() - 1; idx ++)
                layers[dep][idx] -> next = layers[dep][idx + 1];
    }
public:
    void connect(TreeLinkNode * root)
    {
        layers.clear();
        depth = 0;
        traverse(root, 0);
        populate();
    }
};
