class Solution {
public:
    int missingMultiple(vector<int>& nums, int kk) {
        int n=nums.size();
        set<int>st;
        int k=kk;
        
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                st.insert(nums[i]);
            }
        }
        for(auto it:st){
            if(it!=k)return k;
            k+=kk;
        }
        return k;
    }
};