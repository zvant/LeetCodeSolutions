/**
 * https://leetcode.com/problems/partition-list/description/
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

struct ListNode * partition(struct ListNode * head, int x)
{
    if(head == NULL || head -> next == NULL)
        return head;
    
    struct ListNode * h1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    h1 -> next = NULL;
    struct ListNode * p1 = h1;
    
    struct ListNode * h2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    h2 -> next = NULL;
    struct ListNode * p2 = h2;
    
    struct ListNode * ptr = head;
    while(ptr != NULL)
    {
        if(ptr -> val < x)
        {
            p1 -> next = ptr;
            ptr = ptr -> next;
            p1 = p1 -> next;
            p1 -> next = NULL;
        }
        else
        {
            p2 -> next = ptr;
            ptr = ptr -> next;
            p2 = p2 -> next;
            p2 -> next = NULL;
        }
    }
    p1 -> next = h2 -> next;
    head = h1 -> next;
    free(h1);
    free(h2);
    
    return head;
}
