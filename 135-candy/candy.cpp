class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=0;
        vector<int>temp(n,1);
        //check only for left ngbrs
        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                temp[i]=temp[i-1]+1;
            }
        }
        //check for right ngbrs only
        ans+=temp[n-1];
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                temp[i]=max(temp[i],temp[i+1]+1);
            }
            ans+=temp[i];
        }
        return ans;
        
    }
};