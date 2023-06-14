class Solution {
public:
  //优化时间解法
    int fib(int n) {
        // if(n==0)
        //     return 0;
        // int *dp=new int[n+1];
        // dp[0]=0;dp[1]=1;
        // //状态转移
        // for(int i=2;i<=n;++i)
        //     dp[i]=dp[i-1]+dp[i-2];
        // return dp[n];
    //优化空间解法
    if(n==0||n==1)
        return n;
    int dp1=1,dp2=0;
    for(int i=2;i<=n;++i)
    {
        int dp=dp1+dp2;
        dp2=dp1;
        dp1=dp;
    }
    return dp1;
    }
};
