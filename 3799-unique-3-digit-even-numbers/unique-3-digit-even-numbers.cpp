class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        set<pair<int,pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if((i!=j&&i!=k&&j!=k)&&(digits[i]!=0)&&digits[k]%2==0){
                        st.insert({digits[i],{digits[j],digits[k]}});
                    }
                }
            }
        }
        return st.size();
    }
};