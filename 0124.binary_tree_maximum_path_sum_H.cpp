/**
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 * 2015/10
 * 32 ms
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
    int max_path;
    int maxPathDown(TreeNode * root)
    {
        if(root == NULL)
            return 0;
        if(root -> left == NULL && root -> right == NULL)
        {
            if(root -> val > max_path)
                max_path = root -> val;
            return root -> val;
        }
        
        int left_sum = maxPathDown(root -> left);
        int right_sum = maxPathDown(root -> right);
        
        int sums[4];
        sums[0] = root -> val; // root path
        sums[1] = left_sum + root -> val; // left to root path
        sums[2] = right_sum + root -> val; // right to root path
        sums[3] = left_sum + right_sum + root -> val; // left to right path
        
        int max_sum = * max_element(sums, sums + 4);
        if(max_sum > max_path)
            max_path = max_sum;
        
        return * max_element(sums, sums + 3);
    }
public:
    int maxPathSum(TreeNode * root)
    {
        max_path = INT_MIN;
        maxPathDown(root);
        return max_path;
    }
};
