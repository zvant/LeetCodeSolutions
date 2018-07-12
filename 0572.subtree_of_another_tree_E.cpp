/**
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 * 2017/05
 * 25 ms
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
    const static int BUFF_SIZE = 1024;
    int * t_pre = new int[BUFF_SIZE * 4];
    int * t_in  = t_pre + BUFF_SIZE;
    int * s_pre = t_in + BUFF_SIZE;
    int * s_in = s_pre + BUFF_SIZE;
    TreeNode ** nodes = new TreeNode*[BUFF_SIZE];
    
    void serialize(TreeNode * root, TreeNode ** buff, int & idx)
    {
        if(NULL != root)
        {
            buff[idx] = root;
            idx ++;
            serialize(root -> left, buff, idx);
            serialize(root -> right, buff, idx);
        }
    }
    void preorder(TreeNode * root, int * buff, int & idx)
    {
        if(NULL != root)
        {
            buff[idx] = root -> val;
            idx ++;
            preorder(root -> left, buff, idx);
            preorder(root -> right, buff, idx);
        }
    }
    void inorder(TreeNode * root, int * buff, int & idx)
    {
        if(NULL != root)
        {
            inorder(root -> left, buff, idx);
            buff[idx] = root -> val;
            idx ++;
            inorder(root -> right, buff, idx);
        }
    }
public:
    bool isSubtree(TreeNode * s, TreeNode * t)
    {
        int len = 0;
        preorder(t, t_pre, len);
        len = 0;
        inorder(t, t_in, len);
        
        int count = 0;
        serialize(s, nodes, count);
        for(int i = 0; i < count; i ++)
        {
            if(nodes[i] -> val != t -> val)
            {
                continue;
            }
            int idx = 0;
            preorder(nodes[i], s_pre, idx);
            if(idx != len)
            {
                continue;
            }
            idx = 0;
            inorder(nodes[i], s_in, idx);
            if(0 == memcmp(s_in, t_in, len * sizeof(int)) && 0 == memcmp(s_pre, t_pre, len * sizeof(int)))
            {
                return true;
            }
        }
        return false;
    }
};
