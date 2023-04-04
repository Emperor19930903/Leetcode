给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None
        # 区间 [a, b) 包含 k 个待反转元素
        a=b=head
        for i in range(k):
            # 不足 k 个，不需要反转，base case
            if not b:
                return head
            b=b.next
        # 反转前K个元素
        newHead=self.reverse(a,b)
        a.next=self.reverseKGroup(b,k)
        return newHead
     """ 反转区间 [a, b) 的元素，注意是左闭右开 """
    def reverse(self,a:ListNode,b:ListNode)->
        pre,cur,next=None,a,a
        while cur!=b:
            next=cur.next
            cur.next=pre
            pre=cur
            cur=next
        # 返回反转后的头结点
        return pre
