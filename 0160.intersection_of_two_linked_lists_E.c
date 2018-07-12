/**
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 * 2015/07
 * 36 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int length(struct ListNode * head)
{
    int len = 0;
    struct ListNode * ptr;
    for(ptr = head; ptr != NULL; ptr = ptr -> next)
        len ++;
    return len;
}

struct ListNode * getIntersectionNode(struct ListNode * headA, struct ListNode * headB)
{
    int lenA = length(headA);
    int lenB = length(headB);
    if(lenA <= 0 || lenB <= 0)
        return NULL;
    
    struct ListNode * ptrA = headA;
    struct ListNode * ptrB = headB;
    while(ptrA != NULL && ptrB != NULL)
    {
        if(lenA > lenB)
        {
            ptrA = ptrA -> next;
            lenA --;
            continue;
        }
        if(lenA < lenB)
        {
            ptrB = ptrB -> next;
            lenB --;
            continue;
        }
        if(ptrA == ptrB)
            break;
        ptrA = ptrA -> next;
        ptrB = ptrB -> next;
    }
    return ptrA;
}
