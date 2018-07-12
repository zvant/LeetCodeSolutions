/** * https://leetcode.com/problems/add-two-numbers-ii/description/ * 2017/02 * 56 ms *//** * Definition for singly-linked list. * struct ListNode { *     int val; *     ListNode *next; *     ListNode(int x) : val(x), next(NULL) {} * }; */class Solution{private:    int countNodes(ListNode * head)    {        int count = 0;        for(ListNode * ptr = head; ptr != NULL; ptr = ptr -> next)        {            count ++;        }        return count;    }    void fillBits(int * bits, ListNode * head)    {        int idx = 0;        for(ListNode * ptr = head; ptr != NULL; ptr = ptr -> next)        {            * (bits - idx) = ptr -> val;            idx ++;        }    }public:    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)    {        int len1 = countNodes(l1);        int len2 = countNodes(l2);        int len = max(len1, len2) + 1;        int * bits1 = new int[len];        int * bits2 = new int[len];        fillBits(bits1 + len1 - 1, l1);        fillBits(bits2 + len2 - 1, l2);        fill(bits2 + len2, bits2 + len, 0);        fill(bits1 + len1, bits1 + len, 0);                int sum = bits1[0] + bits2[0];        int addition = sum / 10;        ListNode * bit = NULL;        ListNode * result = new ListNode(sum % 10);        for(int idx = 1; idx < len; idx ++)        {            sum = bits1[idx] + bits2[idx] + addition;            addition = sum / 10;            bit = new ListNode(sum % 10);            bit -> next = result;            result = bit;        }        if(0 == result -> val)        {            bit = result;            result = result -> next;            delete bit;        }        delete[] bits1;        delete[] bits2;        return result;    }};