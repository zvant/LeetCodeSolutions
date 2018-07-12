/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 * 2015/08
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
    int count;
    int kth;
    TreeNode * ptr;
    void searchKth(TreeNode * root)
    {
        if(NULL != ptr || NULL == root)
            return;
        if(NULL == root -> left && NULL == root -> right)
        {
            count ++;
            if(count == kth)
                ptr = root;
            return;
        }
        searchKth(root -> left);
        count ++;
        if(count == kth)
        {
            ptr = root;
            return;
        }
        searchKth(root -> right);
    }
    
public:
    int kthSmallest(TreeNode * root, int k)
    {
        count = 0;
        kth = k;
        ptr = NULL;
        searchKth(root);
        if(NULL != ptr)
            return ptr -> val;
        else
            return INT_MAX;
    }
};
