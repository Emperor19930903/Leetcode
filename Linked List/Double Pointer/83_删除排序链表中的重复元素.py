class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node=slow=fast=head
        while fast is not None:
            if fast.val != slow.val:
                slow.next = fast
                slow = slow.next
                
            else:
                fast = fast.next
                slow.next=None     # 取消后面重复的链表
        return node    
