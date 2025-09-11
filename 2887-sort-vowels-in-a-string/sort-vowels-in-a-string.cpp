class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                   c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
        };

        priority_queue<char, vector<char>, greater<char>> pq;
        
        // Step 1: Push all vowels into min-heap
        for (char c : s) {
            if (isVowel(c)) pq.push(c);
        }

        // Step 2: Replace vowels in sorted order
        for (char &c : s) {
            if (isVowel(c)) {
                c = pq.top();
                pq.pop();
            }
        }

        return s;
    }
};
