class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                     29, 31, 37, 41, 43, 47, 53, 59, 61,
                                     67, 71, 73, 79, 83, 89, 97};
        vector<int>frq(101,0);
        for(int i=0;i<n;i++){
            frq[nums[i]]++;
        }
        for(int i=0;i<101;i++){
            if(primes.find(frq[i])!=primes.end())return true;
        }
        return false;
    }
};