# https://leetcode.com/problems/double-a-number-represented-as-a-linked-list
# 2023/09
# 399 ms

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p = head
        head.prev = None
        while p.next is not None:
            p.next.prev = p
            p = p.next
        inc = 0
        while p is not None:
            p.val = p.val * 2 + inc
            inc = p.val // 10
            p.val %= 10
            p = p.prev
        if inc != 0:
            new_node = ListNode(val=inc, next=head)
            head = new_node
        return head
