# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        slow=head
        fast=head.next
        while slow!=fast:
            if not fast or not fast.next:
                return None
            slow=slow.next
            fast=fast.next.next
        slow=head
        fast=fast.next    # 补足少走的那一步
        while slow!=fast:
            slow=slow.next
            fast=fast.next
       
        return slow
