class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        pre=[]
        nums.sort()
        n=len(nums)
        for i in range(n):
            if i>0:
                pre.append(nums[i]+pre[i-1])
            else:
                pre.append(nums[i])
        nums.reverse()
        pre.reverse()
        i=0
        while i<n-2 and nums[i]>=pre[i+1]:
            i+=1
        if i<n-2:
            return pre[i]
        else:
            return -1

            