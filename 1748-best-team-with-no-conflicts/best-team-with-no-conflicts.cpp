class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={ages[i],scores[i]};
        }
        sort(temp.begin(),temp.end());
        vector<int>lis_sum(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            lis_sum[i]=temp[i].second;
            ans=max(ans,lis_sum[i]);
        }

        for(int curr=0;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(temp[curr].second>=temp[prev].second){
                    lis_sum[curr]=max(lis_sum[curr],temp[curr].second+lis_sum[prev]);
                }
                ans=max(ans,lis_sum[curr]);
            }
        }
        return ans;
    }
};