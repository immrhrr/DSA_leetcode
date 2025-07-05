class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        vector<int>frq(501,0);
        for(int i=0;i<n;i++){
            frq[arr[i]]++;
        }
        int ans=-1;
        for(int i=1;i<501;i++){
            if(frq[i]==i){
                ans=i;
            }
        }
        return ans;
    }
};