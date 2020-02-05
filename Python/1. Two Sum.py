class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d={}
        ans=[]
        for i in range(len(nums)):
            d[nums[i]]=i
        for i in range(len(nums)):
            delta=target-nums[i]
            if delta not in d:
                continue
            elif d[delta]==i:
                continue
            else :
                ans=[i,d[delta]]
                break
        return ans
            