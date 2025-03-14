class Solution {
public:
    bool check(vector<int>&candies,int mid,long long k){
        int n=candies.size();
         long long temp=0;
        for(int i=0;i<n;i++){
            temp+=candies[i]/mid;
            if(temp>=k){
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int high=0;
        for(int i=0;i<n;i++){
            high=max(high,candies[i]);
        }
        int low=1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(candies,mid,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};