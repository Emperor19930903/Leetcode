给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')


class Solution:

    def minDistance(self,s1:str,s2:str) ->int:
        # 解法一：定义dp(i,j)返回s1(0...i)和s2(0...j)的最小编辑距离
        # memo=dict()
        # def dp(i,j):
        #     if i==-1: return j+1
        #     if j==-1: return i+1
        #     if(i,j) in memo:
        #         return memo[(i,j)]
        #     if s1[i]==s2[j]:
        #         memo[(i,j)]= dp(i-1,j-1)
        #     else:
        #         memo[(i,j)]= min(
        #             dp(i,j-1)+1,   # 插入
        #             dp(i-1,j)+1,   # 删除
        #             dp(i-1,j-1)+1   # 替换
        #         )
        #     return memo[(i,j)]
        # return dp(len(s1)-1,len(s2)-1);
        # 解法二：自底向上的解法
        import numpy as np
        m = len(s1) + 1
        n = len(s2) + 1
        L = np.zeros((m, n),dtype=int)
        for i in range(m):
            L[i][0] = i
        for i in range(n):
            L[0][i] = i
        for i in range(1,m):
            for j in range(1,n):
                if s1[i-1] == s2[j-1]:
                    L[i][j] = L[i - 1][j - 1]
                else:
                    L[i][j] = min(
                        L[i][j - 1] + 1,
                        L[i - 1][j - 1] + 1,
                        L[i - 1][j] + 1
                    )
        return int(L[m-1][n-1])
                
1.时间复杂度：O（n*m）
2.空间复杂度：O（n*m）,n是word1的长度，m是word2的长度。
