class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        int n=people.size();
        vector<vector<int>>ans;
        for(auto p:people){
            ans.insert(ans.begin()+p[1],p);
        }
        // stack<vector<int>>st;
        // stack<vector<int>>temp;
        // for(int i=0;i<n;i++){
        //     while(st.size()!=people[i][1]){
        //         auto it=st.top();
        //         temp.push(it);
        //         st.pop();
        //     }
        //     st.push(people[i]);
        //     while(!temp.empty()){
        //         st.push(temp.top());
        //         temp.pop();
        //     }
        // }
        // int ind=n-1;
        // while(!st.empty()){
        //     ans[ind--]=st.top();
        //     st.pop();
        // }
        return ans;
    }
};