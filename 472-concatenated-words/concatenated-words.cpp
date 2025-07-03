class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool canForm(const string& word, int start, int count) {
        TrieNode* node = root;
        int n = word.size();
        for (int i = start; i < n; ++i) {
            int idx = word[i] - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
            if (node->isEnd) {
                if (i == n - 1)
                    return true;  
                if (canForm(word, i + 1, count + 1))
                    return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Sort to ensure we build Trie using smaller words first
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<string> result;
        for (string& word : words) {
            if (word.empty()) continue;
            if (canForm(word, 0, 0)) {
                result.push_back(word);
            } else {
                insert(word);  // Insert only if not concatenated
            }
        }
        return result;
    }
};
