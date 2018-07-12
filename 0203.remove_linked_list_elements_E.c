/**
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 * 2015/07
 * 12 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * removeElements(struct ListNode * head, int val)
{
    struct ListNode * tmp;
    while(head != NULL && head -> val == val)
    {
        tmp = head;
        head = head -> next;
        free(tmp);
    }
    tmp = NULL;
    if(head == NULL)
        return NULL;
    
    struct ListNode * p1 = head;
    struct ListNode * p2 = p1 -> next;
    
    while(p2 != NULL)
    {
        if(p2 -> val  == val)
        {
            p1 -> next = p2 -> next;
            free(p2);
        }
        else
        {
            p1 = p1 -> next;
        }
        
        p2 = p1 -> next;
    }
    return head;
}
