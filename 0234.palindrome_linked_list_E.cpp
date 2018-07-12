/**
 * https://leetcode.com/problems/palindrome-linked-list/description/
 * 2015/08
 * 28 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution 
{
private:
    int len;
    ListNode * list;
    void measureLength()
    {
        ListNode * ptr = list;
        len = 0;
        while(ptr != NULL)
        {
            len ++;
            ptr = ptr -> next;
        }
    }
    ListNode * reverseList(ListNode * head)
    {
        if(head == NULL)
            return head;
        
        ListNode * p1 = NULL;
        ListNode * p2 = head;
        ListNode * p3 = p2 -> next;
        while(p3 != NULL)
        {
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3 -> next;
        }
        p2 -> next = p1;
        return p2;
    }

public:
    bool isPalindrome(ListNode * head)
    {
        list = head;
        measureLength();
        if(len < 2)
            return true;
        ListNode * ptr = list;
        int count = 1;
        while(count < len / 2)
        {
            ptr = ptr -> next;
            count ++;
        }
        ListNode * l2;
        if(len % 2 == 0)
            l2 = ptr -> next;
        else
            l2 = ptr -> next -> next;
        
        ptr -> next = NULL;
        ListNode * l1 = reverseList(list);
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val != l2 -> val)
                return false;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if(l1 == l2)
            return true;
        return false;
    }
};
