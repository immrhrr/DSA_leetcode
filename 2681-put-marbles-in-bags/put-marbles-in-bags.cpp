class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>pairsum;
        int n=weights.size();
        for(int i=1;i<n;i++){
            pairsum.push_back(weights[i]+weights[i-1]);
        }
        sort(pairsum.begin(),pairsum.end());
        long long ans=0;
        //last k-1 ka sum -first k-1 ka sum
        for(int i=0;i<k-1;i++){
            ans+=-pairsum[i];
        }
        int m=pairsum.size();
        for(int i=m-1;i>=m-(k-1);i--){
            ans+=pairsum[i];
        }
        return ans;
        
    }
};