class Solution {
public:
    int summ(int x){
        int sum=0;
        while(x>0){
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    static bool cmp(const pair<int,pair<int,int>>a,const pair<int,pair<int,int>>b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        else
        return a.second.first<b.second.first;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,pair<int,int>>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={summ(nums[i]),{nums[i],i}};
        }
        sort(temp.begin(),temp.end(),cmp);
        //now need to find the number of swaps only
        //create a graph initial to fianl index
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[temp[i].second.second]=i;
        }
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]||mp[i]==i)continue;
            int cycle_size=0;
            int j=i;
            while(!vis[j]){
                vis[j]=true;
                j=mp[j];
                cycle_size++;
            }
            if(cycle_size>1){
                cnt+=(cycle_size-1);
            }
        }
        return cnt;
        
    }
};