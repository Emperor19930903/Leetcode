# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
    // 快慢指针初始化指向 head
        fast=slow=head
        # 慢指针走一步，快指针走两步   快指针走到结尾的时候（偶数是nullptr，奇数是尾节点），慢指针指向的就是中间节点
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
        return slow
