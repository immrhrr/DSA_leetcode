class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        //max heap chahiye guru
        long long tot_sum=0;
        for(int i=0;i<n;i++){
            tot_sum+=target[i];
        }
        priority_queue<int>pq(target.begin(),target.end());
        while(pq.top()!=1){
            int maxi=pq.top();
            pq.pop();
            long long rem_sum=tot_sum-maxi;
             if(rem_sum>=maxi||rem_sum<=0){
                return false;
            }
            int temp=maxi%rem_sum;
            if(temp==0){
                if(rem_sum!=1)
                return false;
                else
                return true;
            }
            tot_sum=rem_sum+temp;
            pq.push(temp);
        }
        return true;
    }
};