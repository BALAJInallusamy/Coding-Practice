class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        ans=[]
        for x in nums1:
            mp[x]=1
        for x in nums2:
            if x in mp and mp[x]==1:
                ans.append(x)
                mp[x]-=1
        return ans

        