class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={nums[i],i};
        }
        sort(temp.begin(),temp.end());
        int i=0;
        int j=n-1;
        int sum=0;
        while(j>i){
            sum=temp[i].first+temp[j].first;
            if(sum==target){
                return {temp[i].second,temp[j].second};
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1,-1};
    }
};