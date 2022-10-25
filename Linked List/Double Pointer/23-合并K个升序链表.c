//方法一：顺序合并，先合并两个链表
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *temp=nullptr;
        for(int i=0;i<lists.size();++i)
        {
            temp=Merge(temp,lists[i]);
        }
        return temp;
    }
    ListNode*Merge(ListNode *pHead1,ListNode*pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        ListNode*dummp=new ListNode(0),*head=dummp;
        while(pHead1&&pHead2)
        {
            if(pHead1->val>=pHead2->val)
            {
                head->next=pHead2;
                pHead2=pHead2->next;
            }    
            else
            {
                head->next=pHead1;
                pHead1=pHead1->next;
            }
            head=head->next;   
        }
        head->next=pHead1?pHead1:pHead2;
        return dummp->next;
    }
};
// 1.时间复杂度：假设每个链表的最长长度是 n。在第一次合并后，ans 的长度为 n；第二次合并后，ans 的长度为 2×n，第 i 次合并后，ans 的长度为 i×n。
//第 i 次合并的时间代价是O(n+(i−1)×n)=O(i×n)，那么总的时间代价为 O(∑i=1k(i×n))=O((1+k)⋅k^2×n)=O(k^2n)，故渐进时间复杂度为 O(k^2 n)
// 2.空间复杂度：没有用到与 k 和 n 规模相关的辅助空间，故渐进空间复杂度为 O(1)。

//方法二：分治合并
//将 k 个链表配对并将同一对中的链表合并；第一轮合并以后， k 个链表被合并成了k/2个链表，平均长度为2n/k，然后是 k/4个链表， k/8个链表等等；
//重复这一过程，直到我们得到了最终的有序链表。

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return Merge(lists,0,lists.size()-1);
    }
    ListNode*MergeTwoList(ListNode *pHead1,ListNode*pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        ListNode*dummp=new ListNode(0),*head=dummp;
        while(pHead1&&pHead2)
        {
            if(pHead1->val>=pHead2->val)
            {
                head->next=pHead2;
                pHead2=pHead2->next;
            }    
            else
            {
                head->next=pHead1;
                pHead1=pHead1->next;
            }
            head=head->next;   
        }
        head->next=pHead1?pHead1:pHead2;
        return dummp->next;
    }
    ListNode*Merge(vector<ListNode*>& lists,int l,int r)
    {
        if(l==r)return lists[l];
        if(l>r)return nullptr;
        int mid=(l+r)>>1;
        return MergeTwoList(Merge(lists,l,mid),Merge(lists,mid+1,r));
    }
};
//1.时间复杂度：一共进行logk次合并，每次合并的时间为O（kn），总时间复杂度为O（kn×logk）
//2.空间复杂度：递归会使用到 O(logk) 空间代价的栈空间。

//方法三：最小堆
//第一种形式：
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
//第二种形式：
class Solution {
public:
    struct cmp{
        bool operator()(ListNode*a,ListNode*b)
        {
            return a->val>b->val;       
        }
    };
    //如果把后面两个参数缺省的话，优先队列就是大顶堆，队头元素最大。
    priority_queue<ListNode*,vector<ListNode*>,cmp> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node:lists)
            if(node) q.push(node);
        ListNode head,*tail=&head;
        while(!q.empty())
        {
            ListNode*node=q.top();
            q.pop();
            tail->next=node;
            tail=tail->next;
            if(node->next)q.push(node->next);
        }        
        return head.next;
    }
};
//1.考虑优先队列中的元素不超过k 个，那么插入和删除的时间代价为 O(logk)，这里最多有kn 个点，对于每个点都被插入删除各一次，故总的时间代价即渐进时间复杂度为O(kn×logk)。
//2.空间复杂度：这里用了优先队列，优先队列中的元素不超过 k 个，故渐进空间复杂度为 O(k)。
