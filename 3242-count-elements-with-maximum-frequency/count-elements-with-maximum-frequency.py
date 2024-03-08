
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        ans=0
        maxi=1
        a = [0 for x in range(100)]
        for x in nums: 
            a[x-1]+=1
            if a[x-1]==maxi:
                ans+=1
            if a[x-1]>maxi:
                maxi=a[x-1]
                ans=1
            
        return ans*maxi