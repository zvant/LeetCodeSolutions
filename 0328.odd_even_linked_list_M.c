/**
 * https://leetcode.com/problems/odd-even-linked-list/description/
 * 2016/02
 * 4 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * oddEvenList(struct ListNode * head)
{
    if(head == NULL || head -> next == NULL)
        return head;
    
    struct ListNode * odd_list = head;
    struct ListNode * even_list = head -> next;
    struct ListNode * even_head = even_list;
    struct ListNode * ptr = even_list -> next;
    
    int count = 3;
    while(ptr != NULL)
    {
        if(count & 1)
        {
            odd_list -> next = ptr;
            odd_list = ptr;
        }
        else
        {
            even_list -> next = ptr;
            even_list = ptr;
        }
        
        count ++;
        ptr = ptr -> next;
    }
    
    odd_list -> next = even_head;
    even_list -> next = NULL;
    return head;
}
