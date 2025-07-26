class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conf) {
        vector<vector<int>>temp(n+1);
        for(auto it:conf){
            int a=min(it[0],it[1]);
            int b=max(it[0],it[1]);
            temp[b].push_back(a);
        }
        int max_conf=0;
        int sec_max_conf=0;
        long long valid=0;
        vector<long long>extra(n+1,0);
        for(int end=1;end<=n;end++){
            for(int i=0;i<temp[end].size();i++){
                int curr=temp[end][i];
                if(curr>max_conf){
                    sec_max_conf=max_conf;
                    max_conf=curr;
                }
                else if(curr>sec_max_conf){
                    sec_max_conf=curr;
                }
            }
            valid+=end-max_conf;
            extra[max_conf]+=(max_conf-sec_max_conf);
        }
        return valid+*max_element(extra.begin(),extra.end());
    }
};