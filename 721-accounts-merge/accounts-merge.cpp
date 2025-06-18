class Solution {
public:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }
    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA == rootB)
            return;
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootB] > rank[rootA]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
        return;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j=1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    Union(i, mp[mail], parent, rank);
                }
            }
        }

        unordered_map<int, set<string>> ans;
        for(auto it:mp){
            int ind=it.second;
            ind=find(ind,parent);
            string mail=it.first;
            ans[ind].insert(mail);
        }
        int x=ans.size();
        vector<vector<string>>temp(x);
        int curr=0;
        for(auto it:ans){
            string name=accounts[it.first][0];
            temp[curr].push_back(name);
            vector<string>arr(it.second.begin(),it.second.end());
            for(int i=0;i<arr.size();i++){
                temp[curr].push_back(arr[i]);
            }
            curr++;
        }
        return temp;
    }
};
//step1: kaunsa email kaunsa person ka ->mp1(string ,int)
//step2: find which index names are belonging to same person ->dsu
//step3: merge the emails belonging to same person->mp2(int,set);
//step4: keep the emails in sorted order->itterate mp2 to fill the ans vector