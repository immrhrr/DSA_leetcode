class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n,-1);
        vector<int>right(n,-1);
        //left will store the max val left to it
        //right will store the max val right to it
        int maxi=height[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,height[i]);
            left[i]=maxi;
        }
        maxi=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,height[i]);
            right[i]=maxi;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int l=left[i];
            int r=right[i];
            int ht=min(l,r);
            ans+=(max(ht-height[i],0));
        }
        return ans;
    }
};