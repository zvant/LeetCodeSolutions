/**
 * https://leetcode.com/problems/linked-list-cycle-ii/
 * 2020/01
 * 12 ms
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
public:
    ListNode * detectCycle(ListNode * head)
    {
        ListNode * p1, * p2;
        p1 = p2 = head;
        do {
            if(p1 == nullptr)
            {
                return nullptr;
            }
            else
            {
                p1 = p1 -> next;
            }
            if(p2 == nullptr || p2 -> next == nullptr)
            {
                return nullptr;
            }
            else
            {
                p2 = p2 -> next -> next;
            }
        } while(p1 != p2);
        p1 = head;
        while(p1 != p2)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1;
    }
};
