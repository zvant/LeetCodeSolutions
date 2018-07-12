/**
 * https://leetcode.com/problems/insertion-sort-list/description/
 * 2015/07
 * 76 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * insertionSortList(struct ListNode * head)
{
    struct ListNode * list = (struct ListNode *)malloc(sizeof(struct ListNode));
    list -> next = NULL;
    list -> val = INT_MIN;
    struct ListNode * ptr;
    struct ListNode * post;
    while(head != NULL)
    {
        ptr = list;
        while(ptr != NULL)
        {
            if((ptr -> val) <= (head -> val))
            {
                if(ptr -> next == NULL)
                    break;
                else if((ptr -> next -> val) >= (head -> val))
                    break;
                else
                    ptr = ptr -> next;
            }
            else
                break;
        }
        post = ptr -> next;
        ptr -> next = head;
        head = head -> next;
        ptr -> next -> next = post;
    }
    head = list -> next;
    free(list);
    return head;
}
