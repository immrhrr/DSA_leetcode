class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int n=s1.size();
        int cnt_different=0;
        int first=-1;
        int second=-1;
        for(int i=0;i<n;i++){
            if(cnt_different>2){
                return false;
            }
            if(s1[i]!=s2[i]){
                cnt_different++;
                if(first==-1){
                    first=i;
                }
                else{   
                second=i;
                }
            }

        }
        if(cnt_different>2||cnt_different==1){
                return false;
            }
            if(s1[first]==s2[second]&&s1[second]==s2[first]){
                return true;
            }
            return false;


    }
};