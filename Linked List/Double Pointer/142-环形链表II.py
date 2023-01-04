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
# 解析： 慢指针K步，快指针2K步，相差的K步就是环的长度的倍数。相遇后，任何一个指针回到初始位置，再次相遇时，就是环的入口节点。假设第一次相遇时的节点位置距环入口m，只要再走k-m可以
# 环的入口节点。快指针：K-m=(j-1)L+L-m   L为环的长度，和慢指针情况相同
