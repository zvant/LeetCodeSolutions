/**
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 * 2017/01
 * 39 ms
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
    void deleteNodeRecursive(TreeNode * parent, TreeNode * node)
    {
        if(NULL == parent || NULL == node)
        {
            return;
        }
        int key = node -> val;
        if(NULL == node -> left && NULL == node -> right)
        {
            delete node;
            if(key > parent -> val)
            {
                parent -> right = NULL;
            }
            else
            {
                parent -> left = NULL;
            }
        }
        else if(NULL == node -> left)
        {
            if(key > parent -> val)
            {
                parent -> right = node -> right;
            }
            else
            {
                parent -> left = node -> right;
            }
        }
        else if(NULL == node -> right)
        {
            if(key > parent -> val)
            {
                parent -> right = node -> left;
            }
            else
            {
                parent -> left = node -> left;
            }
        }
        else
        {
            TreeNode * max_node = node -> left;
            TreeNode * max_parent = node;
            while(NULL != max_node -> right)
            {
                max_parent = max_node;
                max_node = max_node -> right;
            }
            node -> val = max_node -> val;
            deleteNodeRecursive(max_parent, max_node);
        }
    }
public:
    TreeNode * deleteNode(TreeNode * root, int key)
    {
        TreeNode * fakeroot = new TreeNode(INT_MIN);
        fakeroot -> right = root;
        TreeNode * node = fakeroot;
        TreeNode * parent = NULL;
        while(NULL != node)
        {
            if(key == node -> val)
            {
                break;
            }
            parent = node;
            if(key > node -> val)
            {
                node = node -> right;
            }
            else
            {
                node = node -> left;
            }
        }
        deleteNodeRecursive(parent, node);
        root = fakeroot -> right;
        delete fakeroot;
        return root;
    }
};
