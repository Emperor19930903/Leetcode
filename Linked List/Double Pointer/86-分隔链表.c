struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
    //创建存放小于x的链表的虚节点和移动节点
		ListNode *node1 = new ListNode(0), *slow = node1;
    //创建存放大于x的链表的虚节点和移动节点
		ListNode *node2 = new ListNode(0), *fast = node2;
		while (head != nullptr)
		{
			if (head->val < x)
			{
				slow->next = head;
				slow = slow->next;
			}
			if (head->val >= x)
			{
				fast->next = head;
				fast = fast->next;
			}
      //断开原链表中的每个节点的next指针,第二种方法：fast->next=nullptr;
			ListNode*temp = head->next;
			head->next = nullptr;
			head =temp;
		}
    //连接两个链表
		slow->next = node2->next;
		return node1->next;
	}
};
