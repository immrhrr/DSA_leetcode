class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        vector<pair<int,pair<int,int>>>temp(n);
        for(int i=0;i<n;i++){
            int data=nums[i][0];
            maxi=max(maxi,data);
            temp[i]={data,{i,0}};
        }
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());
        int left=pq.top().first;
        int right=maxi;
        long long range=(long long)right-left;
        while(true){
            int l=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            long long curr_range=maxi-l;
            if(range>curr_range){
                left=l;
                right=maxi;
                range=curr_range;
            }
            if(nums[row].size()>col+1){
                 pq.push({nums[row][col+1],{row,col+1}});
                 maxi=max(maxi,nums[row][col+1]);
            }
            else{
                break;
            }
        }
        return {left,right};
    }
};