# https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list
# 2023/09
# 111 ms

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    @staticmethod
    def GCD(x: int, y: int) -> int:
        if x < y:
            x, y = y, x
        while True:
            r = x % y
            if r == 0:
                return y
            x, y = y, r

    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        while node is not None and node .next is not None:
            new_node = ListNode(val=self.GCD(node.val, node.next.val), next=node.next)
            node.next = new_node
            node = node.next.next
        return head
