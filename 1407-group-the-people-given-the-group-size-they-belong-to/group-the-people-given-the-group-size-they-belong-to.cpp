class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gsize) {
        int n=gsize.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={gsize[i],i};
        }
        sort(temp.begin(),temp.end());
        vector<vector<int>>ans;
        int ind=0;
        while(ind<n){
            int m=temp[ind].first;
            vector<int>arr;
            for(int j=ind;j<ind+m;j++){
                arr.push_back(temp[j].second);
            }
            ans.push_back(arr);
            ind=ind+m;
        }
        return ans;
        
    }
};