# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummp=ListNode(0,head)
        fast=head
        slow=dummp
        for i in range(n):      
            fast=fast.next
        while fast :
            slow=slow.next
            fast=fast.next
        if slow.next:
            temp=slow.next.next
            slow.next.next=None
            slow.next=temp
        return dummp.next
#不过注意我们又使用了虚拟头结点的技巧，也是为了防止出现空指针的情况，比如说链表总共有 5 个节点，题目就让你删除倒数第 5 个节点，也就是第一个节点，
#那按照算法逻辑，应该首先找到倒数第 6 个节点。但第一个节点前面已经没有节点了，这就会出错。但有了我们虚拟节点 dummy 的存在，就避免了这个问题，能够对这种情况进行正确的删除。
