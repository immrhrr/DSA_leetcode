class Solution {
public:
    void solve_left(vector<int>&left,vector<int>&heights){
         //left side first smaller element index
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
    }

    void solve_right(vector<int>&right,vector<int>&heights){
         //right side first smaller element index
        int n=heights.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        //left side first smaller element index
        //right side first smaller element index
        vector<int>left(n,-1);
        vector<int>right(n,-1);
        solve_left(left,heights);
        solve_right(right,heights);
        int ans=0;
        for(int i=0;i<n;i++){
            int l=left[i];
            int r=right[i];
            int width=r-l-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
};