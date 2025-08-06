class Solution {
public:
    bool possible(unordered_map<int,int>&mp,int limit){
        int temp=0;
        for(auto it:mp){
            int val=it.second;
            temp+=(val+2)/3;
        }
        return temp<=limit;

    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            if(it.second==1)return -1;
        }
        int low=1;
        int high=tasks.size()-1;
        int mid=0;
        int ans=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(possible(mp,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};