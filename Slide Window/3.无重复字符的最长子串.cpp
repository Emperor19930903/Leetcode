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
