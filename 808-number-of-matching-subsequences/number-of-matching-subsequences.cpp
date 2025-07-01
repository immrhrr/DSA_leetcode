class Solution {
public:
    struct trieNode {
        int is_end;
        trieNode* children[26];
        trieNode() {
            is_end = 0;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    void insert(string& word, trieNode* root) {
        trieNode* crawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawl->children[idx]) {
                crawl->children[idx] = new trieNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->is_end++;
    }

    int dfs(trieNode* node, vector<vector<int>>& pos, int idx) {
        int count = 0;

        // If this is the end of a word in the trie
        if (node->is_end > 0) {
            count += node->is_end;
            node->is_end = 0; // Avoid double counting
        }

        // Explore children
        for (int c = 0; c < 26; ++c) {
            if (node->children[c]) {
                // Find the next occurrence of character 'c' in s after index `idx`
                auto& vec = pos[c];
                auto it = upper_bound(vec.begin(), vec.end(), idx);
                if (it != vec.end()) {
                    count += dfs(node->children[c], pos, *it);
                }
            }
        }

        return count;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        trieNode* root = new trieNode();

        // Insert all words into trie
        for (string& word : words) {
            insert(word, root);
        }

        // Preprocess s: store positions of each character
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        // Start DFS from root, beginning before index -1
        return dfs(root, pos, -1);
    }
};
