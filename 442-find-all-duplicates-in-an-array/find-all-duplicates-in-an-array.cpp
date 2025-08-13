class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int nxt=abs(arr[i]);
            if(arr[nxt%n]<0){
                ans.push_back(nxt);
            }
            else{
                arr[nxt%n]=-1*arr[nxt%n];
            }
        }
        return ans;
    }
};