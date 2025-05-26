class Solution {
public:
    bool check_prime(long long x){
        if(x<2)return false;
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0)return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int n=s.size();
        unordered_set<long long>st;
        for(int i=0;i<n;i++){
            string ss;
            for(int j=i;j<n;j++){
                ss+=s[j];
                long long temp=stoll(ss);
                st.insert(temp);
            }
        }
        vector<long long>arr;
        for(auto it:st){
            if(check_prime(it)){
                arr.push_back(it);
            }
            
        }
        sort(arr.rbegin(),arr.rend());
        long long ans=0;
        int m=arr.size();
        for(int i=0;i<min(m,3);i++){
            ans+=arr[i];
        }
        return ans;

        
    }
};