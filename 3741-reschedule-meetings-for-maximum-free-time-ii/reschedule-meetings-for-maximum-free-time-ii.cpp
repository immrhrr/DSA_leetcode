class Solution {
public:
    int maxFreeTime(int event, vector<int>& start, vector<int>& end) {
        //sorted order mein given hai sab kuch
        int n=start.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        vector<int>l(n,0);
        vector<int>r(n,0);
        left[0]=start[0];
        l[0]=left[0];
        right[n-1]=event-end[n-1];
        r[n-1]=right[n-1];
        int temp=0;
        for(int i=1;i<n;i++){
            temp=start[i]-end[i-1];
            left[i]=temp;
            l[i]=max(l[i-1],temp);
        }
        for(int i=n-2;i>=0;i--){
            temp=start[i+1]-end[i];
            right[i]=temp;
            r[i]=max(r[i+1],temp);
        }
        int ans=0;
        int curr=0;
        
        for(int i=0;i<n;i++){
            temp=end[i]-start[i];
            curr=left[i]+right[i];
                int peeche=i-1;
                int aage=i+1;
                if((peeche>=0&&l[peeche]>=temp)||(aage<n&&r[aage]>=temp)){
                    curr+=temp;
                }
            ans=max(ans,curr);
        }
        return ans;
    }
};