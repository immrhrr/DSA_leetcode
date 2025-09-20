class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        if(n==0){
            return m;
        }
        vector<int>frq(26,0);
        for(int i=0;i<m;i++){
            frq[tasks[i]-'A']++;
        }
        //max-heap
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(frq[i]>0){
                pq.push(frq[i]);
            }
        }
        int ans=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int f=pq.top();
                    f--;
                    pq.pop();
                    temp.push_back(f);
                }
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0){
                    pq.push(temp[i]);
                }
            }
            if(pq.empty()){
                ans+=temp.size();
            }
            else{
                ans+=(n+1);
            }
        }
        return ans;
    }
};