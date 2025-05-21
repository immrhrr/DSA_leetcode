class Solution {
public:
     int count(int curr,int m,int n){
        int sum=0;
        for(int i=1;i<=m;i++){
            sum+=min(curr/i,n);
        }
        return sum;
    }
    int findKthNumber(int m, int n, int k) {
         int low=1;
        int high=m*n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=count(mid,m,n);
            if(temp>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};