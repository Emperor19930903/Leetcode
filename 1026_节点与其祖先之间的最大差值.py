from typing import Optional
import math
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        res = 0

        def getMinMax(root: Optional[TreeNode], res: int) -> list:
            if root is None:
                return [math.exp(5), math.exp(-5)]
            leftMinMax = getMinMax(root.left, res)
            rightMinMax = getMinMax(root.right, res)
            rootMin = min(root.val, leftMinMax[0], rightMinMax[0])
            rootMax = max(root.val, rightMinMax[1], rightMinMax[1])
            res = max(res, rootMax - root.val, root.val - rootMin)
            return [rootMin, rootMax]

        getMinMax(root, res)
        return res

if '__name__'== '__main__':
    p2=TreeNode(3)
    p1=TreeNode(2,p2)
    s=Solution()
    s.maxAncestorDiff(p1)

