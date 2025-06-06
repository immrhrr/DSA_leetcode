class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end)return 0;
        int n=bank.size();
        int ans=0;
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            st.insert(bank[i]);
        }
        queue<string>q;
        vector<char>vec={'A','T','G','C'};
        q.push(start);
        while(!q.empty()){
            int m=q.size();
            ans++;
            while(m--){
                string curr=q.front();
                q.pop();
                for(int i=0;i<end.size();i++){
                    string temp=curr;
                    for(int j=0;j<4;j++){
                        temp[i]=vec[j];
                        if(st.find(temp)!=st.end()){
                            if(temp==end)return ans;
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};