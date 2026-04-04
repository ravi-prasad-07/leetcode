class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n=len(nums)-1
        for i in range(0,n,2):
            if(nums[i]!=nums[i+1]):
                return nums[i]
        
        return nums[-1]