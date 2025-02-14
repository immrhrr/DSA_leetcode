class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return stones[0];
        }
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int big=pq.top();
            pq.pop();
            int small=pq.top();
            pq.pop();
            if(small!=big){
                pq.push(big-small);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};