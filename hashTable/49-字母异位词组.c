//由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，故可以将排序之后的字符串作为哈希表的键
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left=0,right=0,res=1;
        int n=s.size();
        if (n==0)
            return 0;
        while(right<s.size()-1)
        {
            set.insert(s[right++]);
            while(set.count(s[right]))
                set.erase(s[left++]);
            res=max(res,right-left+1);
        }
        return res;

    }
};
//1.时间复杂度：O（nklogk），其中n是strs中的字符串的数量，k是strs中的字符串的最大长度。需要遍历 n 个字符串，对于每个字符串，需要 O(klogk) 的时间进行排序以及 O(1) 的时间更新哈希表，因此总时间复杂度是O(nklogk)。
//2.空间复杂度：O（nk）,主要为哈希表所占用的空间。
