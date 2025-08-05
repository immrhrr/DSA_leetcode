class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        //i want to find the minimum sum of subarray of len n-k
        int n=card.size();
        int sum=0;
        int tot=0;
        for(int i=0;i<n-k;i++){
            sum+=card[i];
            tot+=card[i];
        }

        int ans=sum;
        int start=0;
        for(int end=n-k;end<n;end++){
            tot+=card[end];
            sum=sum-card[start];
            start++;
            sum=sum+card[end];
            ans=min(ans,sum);
        }
        return tot-ans;
        
    }
};