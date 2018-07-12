/**
 * https://leetcode.com/problems/reverse-linked-list/description/
 * 2015/07
 * 0 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * reverseList(struct ListNode * head)
{
    if(head == NULL)
        return head;
    
    struct ListNode * p1 = NULL;
    struct ListNode * p2 = head;
    struct ListNode * p3 = p2 -> next;
    while(p3 != NULL)
    {
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3 -> next;
    }
    p2 -> next = p1;
    return p2;
}
