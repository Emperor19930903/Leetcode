# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        ans=-1
        rootvalue=root.val
        def dfs(node:TreeNode)->None:
            nonlocal ans
            if not node:
                return
            if ans!=-1 and node.val>=ans:  # 找到第二小才能进行这个判断
                return
            if node.val>rootvalue:
                ans=node.val
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return ans
