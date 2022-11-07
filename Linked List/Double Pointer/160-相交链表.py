# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        Node1=headA
        Node2=headB
        while Node1.next or Node2.next:
            if Node1.next is None:
                Node1.next=headB
            if Node2.next is None:
                Node2.next=headA
            Node1=Node1.next
            Node2=Node2.next
            if Node1.val==Node2.val:
                return Node1
        return None
   
#1.时间复杂度：O（m+n）
#2.空间复杂度：O（1）
## C++版本
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

