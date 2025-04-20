class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gsize) {
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> ans;

        for (int i = 0; i < gsize.size(); i++) {
            groups[gsize[i]].push_back(i);
            if (groups[gsize[i]].size() == gsize[i]) {
                ans.push_back(groups[gsize[i]]);
                groups[gsize[i]].clear();
            }
        }
        return ans;
    }
};
