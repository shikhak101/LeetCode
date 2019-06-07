class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        """
        for (i,num) in enumerate(nums):
            j = i+1
            while j<len(nums):
                if nums[j]+nums[i] == target:
                    return [i,j]
                j+=1
        
        arr = nums.copy()
        arr.sort()
        low = 0
        high = len(arr)
        mid = int((low+high)/2)
        while arr[mid] > target:
            high = mid+1
            mid = int((low + high)/2)
        while low<high:
            temp = low+1
            while temp<high:
                if arr[low]+arr[temp] == target:
                    i = nums.index(arr[low])
                    nums[i] = float("-inf")
                    j = nums.index(arr[temp])
                    return [i,j]
                temp +=1
            low+=1
        """   
        my_dict = {}
        result = []
        for i in range(len(nums)):
            my_dict[nums[i]] = i
        for i in range(len(nums)):
            lookfor = target- nums[i]
            if lookfor in my_dict and my_dict.get(lookfor) != i:
                return [i,my_dict.get(lookfor)]
                