给定一个链表的 头节点 head ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
示例
输入: head = [1,2,3,3,2,1]
输出: true



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr)
            return true;
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *node=nullptr;
        //左闭右开的区间
        while(slow!=nullptr)
        {
            ListNode *next=slow->next;
            slow->next=node;
            node=slow;
            slow=next;
        }
        while(node!=nullptr)
        {
            if(node->val!=head->val)
                return false;
            node=node->next;
            head=head->next;
        }
        return true;
    }
};
