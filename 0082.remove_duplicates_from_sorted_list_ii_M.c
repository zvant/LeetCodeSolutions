/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 * 2015/09
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
    if(head == NULL || head -> next == NULL)
        return head;
    
    struct ListNode * list = (struct ListNode *)malloc(sizeof(struct ListNode));
    list -> val = (head -> val) - 1;
    list -> next = head;
    
    struct ListNode * prev = list;
    struct ListNode * begin = head;
    struct ListNode * end = head -> next;
    
    while(NULL != end)
    {
        if(begin -> val != end -> val)
        {
            if(end -> next == NULL)
                break;
            
            prev = begin;
            begin = end;
            end = begin -> next;
        }
        else
        {
            while(end != NULL && end -> val == begin -> val)
            {
                struct ListNode * tmp = end;
                end = end -> next;
                free(tmp);
            }
            free(begin);
            begin = end;
            prev -> next = begin;
            if(begin == NULL)
                break;
            
            end = begin -> next;
        }
    }
    head = list -> next;
    free(list);
    return head;
}
