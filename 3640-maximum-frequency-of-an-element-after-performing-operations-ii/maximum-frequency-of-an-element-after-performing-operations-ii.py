class Solution:
    def maxFrequency(self, nums: List[int], k: int, op: int) -> int:
        n=len(nums)
        freq={}
        rangee={}
        for i in range(n):
            left=nums[i]-k
            right=nums[i]+k
            if left in rangee:
                rangee[left]+=1
            else:
                rangee[left]=1
            if(nums[i] in rangee ):
                rangee[nums[i]]+=0
            else:
                rangee[nums[i]]=0
            if right+1 in rangee:
                rangee[right+1]-=1
            else:
                rangee[right+1]=-1
            if nums[i]in freq:
                freq[nums[i]]+=1
            else:
                freq[nums[i]]=1
        curr=0
        ans=1
        for key in sorted(rangee.keys()):
            rangee[key]+=curr
            curr=rangee[key]
            if key in freq:
                temp=freq[key]+min(curr-freq[key],op)
            else:
                temp=min(curr,op)
            ans=max(ans,temp)
        return ans
    

        


            
            
        