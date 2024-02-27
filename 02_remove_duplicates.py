class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cambio = 1 #Empieza en 1
        for x in range(1,len(nums)):
            if nums[x] != nums[x-1]:
                nums[cambio] = nums[x]
                cambio +=1
        return cambio