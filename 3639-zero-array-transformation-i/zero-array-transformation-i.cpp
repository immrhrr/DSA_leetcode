class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n);
        int m=queries.size();
        for(int i=0;i<m;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            diff[start]+=1;
            if(end+1<n){
                diff[end+1]+=-1;
            }
        }
        for(int i=1;i<n;i++){
            diff[i]=diff[i-1]+diff[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>diff[i])return false;
        }
        return true;
        
    }
};