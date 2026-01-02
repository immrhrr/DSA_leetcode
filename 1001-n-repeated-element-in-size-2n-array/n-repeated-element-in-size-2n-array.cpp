class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n2=nums.size();
        int n=n2/2;
        //it has exactly n+1 unique elements in the vector
        unordered_map<int,int>mp;
        for(int i=0;i<n2;i++){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second==n)return it.first;
        }
        return -1;

    }
};