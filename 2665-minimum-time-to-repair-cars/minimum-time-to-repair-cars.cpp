class Solution {
public:
    bool check(vector<int>&ranks,long long mid,int cars){
        int n=ranks.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            long long temp=mid/ranks[i];
            cnt+=sqrt(temp);
        }
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        int mini=INT_MAX;
        for(auto rank:ranks)
        mini=min(mini,rank);
        long long low=0;
       long long high = static_cast<long long>(mini) * (static_cast<long long>(cars) * static_cast<long long>(cars));

        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(ranks,mid,cars)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};