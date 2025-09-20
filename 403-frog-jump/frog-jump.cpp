class Solution {
public:
    int dest=0;
    bool solve(vector<int>&stones,unordered_map<int,int>&mp,int last,int curr_ind,vector<vector<int>>&dp){
        int n=stones.size();
        if(curr_ind==n-1) return true;
        if(dp[last][curr_ind]!=-1) return dp[last][curr_ind];

        bool op1=false, op2=false, op3=false;

        // jump (last - 1) allowed if > 0
        if(last-1 > 0 && mp.find(stones[curr_ind] + last - 1) != mp.end()){
            op1 = solve(stones, mp, last-1, mp[stones[curr_ind]+last-1], dp);
        }

        // jump (last)
        if(last > 0 && mp.find(stones[curr_ind] + last) != mp.end()){
            op2 = solve(stones, mp, last, mp[stones[curr_ind]+last], dp);
        }

        // jump (last + 1)
        if(last+1 > 0 && mp.find(stones[curr_ind] + last + 1) != mp.end()){
            op3 = solve(stones, mp, last+1, mp[stones[curr_ind]+last+1], dp);
        }
        
        return dp[last][curr_ind] = op1 | op2 | op3;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(n==1) return true;
        if(stones[1] != 1) return false; // must first jump 1

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }

        vector<vector<int>> dp(2001, vector<int>(2001,-1));
        return solve(stones, mp, 1, 1, dp); // ✅ start at index=1 with last=1
    }
};
