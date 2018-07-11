/**
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 * 2015/07
 * 4 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * mergeTwoLists(struct ListNode * l1, struct ListNode * l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * p = head;
    p -> next = NULL;
    struct ListNode * p1 = l1;
    struct ListNode * p2 = l2;
    while(p1 != NULL && p2 != NULL)
    {
        while(p1 != NULL && p2 != NULL && (p1 -> val <= p2 -> val))
        {
            p -> next = p1;
            p1 = p1 -> next;
            p = p -> next;
            p -> next = NULL;
        }
        while(p1 != NULL && p2 != NULL && (p2 -> val <= p1 -> val))
        {
            p -> next = p2;
            p2 = p2 -> next;
            p = p -> next;
            p -> next = NULL;
        }
    }
    if(p1 != NULL)
        p -> next = p1;
    else
        p -> next = p2;
    p = head;
    head = head -> next;
    free(p);
    return head;
}
