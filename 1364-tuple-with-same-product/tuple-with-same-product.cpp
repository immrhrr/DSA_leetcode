class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto it:mp){
            int temp=it.second;
            ans+=(temp*(temp-1)*4);
        }
        return ans;

    }
};