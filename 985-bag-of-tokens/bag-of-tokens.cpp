class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        if(n==0){
            return 0;
        }
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=n-1;
        int ans=0;
        int  score=0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
                ans=max(ans,score);
            }
            else{
                if(score>0){
                    score--;
                    power+=tokens[j];
                    j--;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};