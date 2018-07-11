/**
 * https://leetcode.com/problems/add-two-numbers/description/
 * 2015/07
 * 20 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * addTwoNumbers(struct ListNode * l1, struct ListNode * l2)
{
    if(l1 == NULL && l2 == NULL)
        return NULL;
    struct ListNode * sum = (struct ListNode *)malloc(sizeof(struct ListNode));
    sum -> next = NULL;
    struct ListNode * p1 = l1;
    struct ListNode * p2 = l2;
    struct ListNode * p3 = sum;
    
    int val1, val2, add;
    int flag = 0;
    while(true)
    {
        if(p1 == NULL && p2 == NULL && flag == 0)
            break;
        val1 = 0;
        val2 = 0;
        if(p1 != NULL)
        {
            val1 = p1 -> val;
            p1 = p1 -> next;
        }
        if(p2 != NULL)
        {
            val2 = p2 -> val;
            p2 = p2 -> next;
        }
        add = val1 + val2 + flag;
        p3 -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p3 = p3 -> next;
        p3 -> next = NULL;
        p3 -> val = add % 10;
        flag = add / 10;
    }
    struct ListNode * tmp = sum;
    sum = sum -> next;
    free(tmp);
    return sum;
}
