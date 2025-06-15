class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        int mod=1e9+7;
        unordered_map<int,int>mp_right;
        for(int i=1;i<n;i++){
            mp_right[nums[i]]++;
        }
        unordered_map<int,int>mp_left;
        int ans=0;
        for(int i=1;i<n-1;i++){
            mp_right[nums[i]]--;
            if(mp_right[nums[i]]==0){
                mp_right.erase(nums[i]);
            }
            mp_left[nums[i-1]]++;
            int need=nums[i]*2;
            if(mp_left.find(need)==mp_left.end()||mp_right.find(need)==mp_right.end()){
                continue;
            }
            int left=mp_left[need];
            int right=mp_right[need];
            ans=(ans+(((long long)left*right))%mod)%mod;
        }
        return ans;
    }
};