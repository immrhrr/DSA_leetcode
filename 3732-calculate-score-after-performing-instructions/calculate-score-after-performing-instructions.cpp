class Solution {
public:
    long long calculateScore(vector<string>& ins,vector<int>& val) {
        int n=val.size();
        int ind=0;
        long long score=0;
        vector<bool>vis(n,false);
        while(ind>=0&&ind<n&&vis[ind]==false){
             vis[ind]=true;
            if(ins[ind]=="add"){
                score+=val[ind];
                ind++;  
            }
            else if(ins[ind]=="jump"){
                ind=ind+val[ind];
            }
        }
        return score;
        
    }
};