class Solution {
public:
    int ladderLength(string start, string end, vector<string>& bank) {
        if(start==end)return 0;
        int n=bank.size();
        int ans=1;
        unordered_set<string>st(bank.begin(),bank.end());
        if(st.find(end)==st.end())return 0;
        queue<string>q;
        vector<char>vec={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        q.push(start);
        while(!q.empty()){
            int m=q.size();
            ans++;
            while(m--){
                string curr=q.front();
                q.pop();
                for(int i=0;i<end.size();i++){
                    string temp=curr;
                    for(int j=0;j<26;j++){
                        if (temp[i] == vec[j]) continue;

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
        return 0;
        
    }
};