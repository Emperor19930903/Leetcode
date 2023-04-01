class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //数组大小<3时
        if(nums.size()<3)
        {
            int ans=0;
            for(int l:nums)ans+=1;
            return ans;
        }
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2],len=nums.size();
        int left,right;
        for(int i=0;i<len;++i)
        {
            left=i+1;right=len-1;
            while(left<right)
            {
                int three=nums[left]+nums[right]+nums[i];
                if(abs(three-target)<abs(ans-target))
                    ans=three;
                if(three>=target)
                {
                    right--;
                }
                if(three<target)
                    left++;
            }
        }
        return ans;
    }
};
