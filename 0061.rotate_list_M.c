/**
 * https://leetcode.com/problems/rotate-list/description/
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
struct ListNode * rotateRight(struct ListNode * head, int k)
{
    if(head == NULL || head -> next == NULL || k <= 0)
        return head;
    
    int len = 0;
    struct ListNode * ptr = head;
    struct ListNode * tail;
    while(ptr != NULL)
    {
        len ++;
        tail = ptr;
        ptr = ptr -> next;
    }
    k = k % len;
    if(k == 0)
        return head;
    
    int i = len - k;
    ptr = head;
    struct ListNode * prev;
    for(; i > 0; i --)
    {
        prev = ptr;
        ptr = ptr -> next;
    }
    tail -> next = head;
    prev -> next = NULL;
    return ptr;
}
