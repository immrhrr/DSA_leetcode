class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> frq(101, 0);  // freq of each number
        int maxi = 0, countMax = 0;

        for (int x : nums) {
            frq[x]++;
            if (frq[x] > maxi) {
                maxi = frq[x];       // new maximum frequency
                countMax = 1;        // reset count to this element
            } else if (frq[x] == maxi) {
                countMax++;          // another element reached max freq
            }
        }
        return maxi * countMax;
    }
};
