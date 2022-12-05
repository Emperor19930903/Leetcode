  def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
      successor=None
      # 将链表前n个节点反转
      def reverseN(head:Optional[ListNode],n:int):
          if n==1:
              self.successor=head.next
              return head
          last=reverseN(head.next,n-1)
          head.next.next=head
          head.next=self.successor
          return last
       # base case
      if left==1:
          return reverseN(head,right)
       # 前进到反转的起点触发   base case
      head.next=self.reverseBetween(head.next,left-1,right-1)
      return head
# 时间复杂度：O（n）
# 空间复杂度：O（n）
