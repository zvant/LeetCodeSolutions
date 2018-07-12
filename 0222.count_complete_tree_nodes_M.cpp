/**
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 * 2015/10
 * 204 ms
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
    int pow_int(int base, int power)
    { // pow_int(0, 0) == 1
        int result = 1;
        while(power > 0)
        {
            result *= base;
            power --;
        }
        return result;
    }
public:
    int countNodes(TreeNode * root)
    {
        if(NULL == root)
            return 0;
        
        TreeNode * ptr;
        int depth_l = 0;
        for(ptr = root -> left; NULL != ptr; ptr = ptr -> left)
            depth_l ++;
        int depth_r = 0;
        for(ptr = root -> right; NULL != ptr; ptr = ptr -> right)
            depth_r ++;
        if(depth_l == depth_r)
            return pow_int(2, depth_l + 1) - 1;
        else
            return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
