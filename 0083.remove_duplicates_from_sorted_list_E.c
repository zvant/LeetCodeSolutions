/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
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
struct ListNode * deleteDuplicates(struct ListNode * head)
{
    if(NULL == head)
        return head;
    
    struct ListNode * ptr1, * ptr2;
    ptr1 = head;
    ptr2 = head -> next;
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 -> val == ptr2 -> val)
        {
            ptr1 -> next = ptr2 -> next;
            free(ptr2);
            ptr2 = ptr1 -> next;
        }
        else
        {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
    }
    return head;
}
