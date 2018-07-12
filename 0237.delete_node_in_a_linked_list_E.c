/**
 * https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 * 2015/08
 * 4 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode * node)
{
    if(node == NULL || (node -> next == NULL))
        return;
    node -> val = node -> next -> val;
    struct ListNode * tmp = node -> next;
    node -> next = node -> next -> next;
    free(tmp);
    return;
}
