class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int m) {
        int n = hand.size();
        if (n % m != 0)
            return false;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }
        for (int i = 0; i < n/m; i++) {
            int temp = m;
            
                int val = mp.begin()->first;
                int need = val;
                while (temp--) {
                    if (mp.find(need) == mp.end()) {
                        return false;
                    }
                    mp[need]--;
                    if (mp[need] == 0) {
                        mp.erase(need);
                    }
                    need++;
                }
            
        }
        return true;
    }
};