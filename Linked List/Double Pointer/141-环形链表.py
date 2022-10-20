class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        slow = head
        fast = head.next    # fast先走一步 能进去下面的循环条件

        while slow != fast:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next
        
        return True
      """1.时间复杂度：O（n）
         2.空间复杂度：O（1）"""
