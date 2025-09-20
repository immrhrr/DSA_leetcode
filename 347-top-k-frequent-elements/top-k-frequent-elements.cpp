class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        vector<pair<int,int>>temp;
        for(auto it:mp){
            int frq=it.second;
            int val=it.first;
            temp.push_back({frq,val});
        }
        sort(temp.rbegin(),temp.rend());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;

    }
};