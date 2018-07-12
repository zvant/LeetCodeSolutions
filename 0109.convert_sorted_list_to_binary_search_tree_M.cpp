/**
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 * 2015/08
 * 28 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    vector<ListNode *> nodes;
    TreeNode * convert(int begin, int end)
    {
        if(end <= begin)
            return NULL;
        int mid = (begin + end) / 2;
        TreeNode * root = new TreeNode(nodes[mid] -> val);
        if(mid == begin)
            return root;
        root -> left = convert(begin, mid);
        root -> right = convert(mid + 1, end);
        return root;
    }
public:
    TreeNode * sortedListToBST(ListNode * head)
    {
        if(NULL == head)
            return NULL;
        nodes.clear();
        for(ListNode * ptr = head; ptr != NULL; ptr = ptr -> next)
            nodes.push_back(ptr);
        
        return convert(0, nodes.size());
    }
};
