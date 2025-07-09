class Solution {
public:
    int maxFreeTime(int event, int k, vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<vector<int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={start[i],end[i]};
        }
       sort(temp.begin(),temp.end());
       vector<int>arr;
       int last=0;
       for(int i=0;i<n;i++){
        int space=temp[i][0]-last;
        arr.push_back(space);
        if(space!=0)
        arr.push_back(0);
        last=temp[i][1];
       }
       arr.push_back(event-temp[n-1][1]);
       int ans=0;
       int i=0;
       int j=0;
       n=arr.size();
       int curr=0;
       int cnt_zero=0;
       while(j<n){
        if(arr[j]==0){
           cnt_zero++;
        }
        curr+=arr[j];
        while(i<j&&cnt_zero>k){
            if(arr[i]==0){
                cnt_zero--;
            }
            curr-=arr[i];
            i++;
            
        }
        ans=max(ans,curr);
        j++;
       }
       return ans;
    }
};