class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int t) {
        int n=arr.size();
        int i=0;
        int j=0;
        int curr=0;
      
        int ans=INT_MAX;
       
        vector<int>temp(n,INT_MAX);
        int best=INT_MAX;
        while(j<n){
            curr+=arr[j];
            while(i<j&&curr>t){
                curr-=arr[i++];
            }
            if(curr==t){
                int len=j-i+1;
                if(i>0&&temp[i-1]!=INT_MAX)
                    ans=min(ans,len+temp[i-1]);
                best=min(best,len);
            }
            temp[j]=best;
            j++;
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};