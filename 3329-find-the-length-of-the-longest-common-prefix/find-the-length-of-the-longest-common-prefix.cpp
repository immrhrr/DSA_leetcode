class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        unordered_set<int>st;
        for(int i=0;i<n1;i++){
            int curr=arr1[i];
            while(curr>0&&st.find(curr)==st.end()){
                st.insert(curr);
                curr=curr/10;
            }
        }
        int ans=0;
        for(int i=0;i<n2;i++){
            int curr=arr2[i];
            while(curr>0&&st.find(curr)==st.end()){
                curr=curr/10;
            }
            if(st.find(curr)!=st.end()){
                int temp=0;
                while(curr>0){
                    temp++;
                    curr=curr/10;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
        
    }
};