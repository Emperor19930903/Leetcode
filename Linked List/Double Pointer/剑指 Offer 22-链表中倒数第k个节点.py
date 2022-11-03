# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if k<0 or head is None:
            return None
        slow=fast=head
        for i in range(k):         
            fast=fast.next
        while fast:
            slow=slow.next
            fast=fast.next
        return slow
