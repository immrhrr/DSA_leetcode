class Solution {
public:
    static bool comp(const pair<int,int>&a,const pair<int,int>&b){
        if(a.first!=b.first){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
    static bool comp2(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={nums[i],i};
        }
        sort(temp.begin(),temp.end(),comp);
        sort(temp.begin(),temp.begin()+k,comp2);
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=temp[i].first;
        }
        return ans;
    }
};