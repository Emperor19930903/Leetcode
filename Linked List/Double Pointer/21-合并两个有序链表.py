# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
       # 这段可以不要
#         if list1 is None:
#             return list2
#         if list2 is None:
#             return list1
        dummp=head=ListNode(0)    # 创建新链表时产生的虚节点
        while list1 and list2:
            if list1.val<=list2.val:
                head.next=list1
                list1=list1.next
            else:
                head.next=list2
                list2=list2.next
            head=head.next
        if list1:
            head.next=list1
        elif list2:
            head.next=list2
        return dummp.next
