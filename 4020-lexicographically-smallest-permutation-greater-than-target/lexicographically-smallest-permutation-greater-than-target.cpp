class Solution {
public:
   string res="";
   bool solve(vector<int>&count,string curr,int i,string target,bool greater){
    if(i==target.size()){
        if(greater){
            res=curr;
            return true;
        }
        return false;
    }
    for(char ch='a';ch<='z';ch++){
        if(count[ch-'a']==0){
            continue;
        }
        if(greater==false&&ch<target[i]){
            continue;
        }
        curr.push_back(ch);
        count[ch-'a']--;
        bool is_greater=greater||ch>target[i];
        if(solve(count,curr,i+1,target,is_greater))
        return true;
        curr.pop_back();
        count[ch-'a']++;
    }
    return false;

   }
    string lexGreaterPermutation(string s, string target) {
        vector<int>count(26,0);
        for(auto ch:s){
            count[ch-'a']++;
        }
        string curr="";
        solve(count,curr,0,target,false);
        return res;
        
    }
};