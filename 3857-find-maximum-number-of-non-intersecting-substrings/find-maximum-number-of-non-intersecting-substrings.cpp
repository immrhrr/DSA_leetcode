class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.size();
        int ans=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            //agar same char pehle se present nhi hai
            if(mp.find(word[i])==mp.end()){
                mp[word[i]]=i;
            }
            //same char pehle se map mein present hai
            //present hai toh dusra condition check kro
            else{
                int last=mp[word[i]];
                //second condition pass
                if(i-last>=3){
                    ans++;
                    mp.clear();
                }
                //second condition failed
                else{
                    continue;
                }

            }

        }
        return ans;
        
        
    }
};