class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node=slow=fast=head
        while fast is not None:
            if fast.val != slow.val:
                slow.next = fast
                slow = slow.next
                
            else:
                fast = fast.next
                slow.next=None     # 断开与后面重复元素的连接
        return node    
# 像 Java/Python 这类带有垃圾回收的语言，可以帮我们自动找到并回收这些「悬空」的链表节点的内存，而像 C++ 这类语言没有自动垃圾回收的机制，确实需要我们编写代码时手动释放掉这些节点的内存。
