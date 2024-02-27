class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cambios = 0
        len_nums = len(nums)
        for x in range(len_nums):
            if nums[x]!=val:
                nums[cambios] = nums[x]
                cambios +=1
        return cambios