class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> mp;
        int cons = 0, n = word.size();

        // Prefix array to store the next consonant position
        vector<int> pref(n);
       pref[n-1]=n;
        for (int i = n - 1; i > 0; i--) {
            if (vowels.find(word[i]) == vowels.end()) {
                pref[i-1] = i;
            } else {
                pref[i-1] = pref[i];
            }
        }

        int i = 0, j = 0;
        long long ans=0;

        while (j < n) {
            char ch = word[j];
            if (vowels.find(ch) != vowels.end()) {
                mp[ch]++;
            } else {
                cons++;
            }

            // Shrink window if too many consonants
            while (cons > k) {
                char leftChar = word[i];
                if (vowels.find(leftChar) != vowels.end()) {
                    mp[leftChar]--;
                    if (mp[leftChar] == 0) {
                        mp.erase(leftChar);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            // If all vowels are present & consonants == k, add valid substrings
            while (mp.size() == 5 && cons == k) {
                ans += pref[j] - j; // Fix: Correct substring counting
                 char leftChar = word[i];
                if (vowels.find(leftChar) != vowels.end()) {
                    mp[leftChar]--;
                    if (mp[leftChar] == 0) {
                        mp.erase(leftChar);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};
