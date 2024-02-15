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
        #5 5  5
        #5 10 15
        for j in range(1,n):
            if nums[-j]<pre[-j-1]:
                if j<n-1:
                    return pre[-j]
                else:
                    return -1
            else:
                continue
        return -1
        

            