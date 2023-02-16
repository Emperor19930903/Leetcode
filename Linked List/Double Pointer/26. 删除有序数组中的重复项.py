class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow=0
        fast=1   # 从0或1开始都可以
        while fast<len(nums):
            if nums[fast]==nums[slow]:
                fast=fast+1
            else:
                slow=slow+1
                nums[slow]=nums[fast] 
        return slow+1
        
#1.时间复杂度：O（n）
#2.空间复杂度:O（n）
