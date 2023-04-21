编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。


示例1：
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]



class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int left=0,right=n-1;
        while(left<right)
        {
            swap(s[left++],s[right--]);
        }
    }
};


1.时间复杂度：O(N)O(N)O(N)，其中 NNN 为字符数组的长度。一共执行了 N/2N/2N/2 次的交换。
2.空间复杂度：O(1)O(1)O(1)。只使用了常数空间来存放若干变量。
