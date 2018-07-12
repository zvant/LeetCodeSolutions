/**
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 * 2015/07
 * 28 ms
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator 
{
private:
    stack<int> s;
    void initIterator(TreeNode * root)
    {
        if(NULL == root)
            return;
        
        initIterator(root -> right);
        s.push(root -> val);
        initIterator(root -> left);
    }
public:
    BSTIterator(TreeNode * root)
    {
        initIterator(root);
    }
    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return (! s.empty());
    }
    /** @return the next smallest number */
    int next()
    {
        if(s.empty())
            return 0;
        int min = s.top();
        s.pop();
        return min;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
