class Solution {
public:
    struct trieNode {
        int count;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        newNode->count = 0;
        return newNode;
    }

    void insert(string& word, trieNode*& root) {
        trieNode* crawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawl->children[idx]) {
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
            crawl->count++;
        }
    }

    void remove(string& word, trieNode*& root) {
        trieNode* crawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            crawl = crawl->children[idx];
            crawl->count--;
        }
    }

    void deleteTrie(trieNode*& root) {
        if (!root) return;
        for (int i = 0; i < 26; i++) {
            deleteTrie(root->children[i]);
        }
        delete root;
    }

    string bfs(trieNode* root, int k) {
        queue<pair<trieNode*, string>> q;
        string max_word = "";

        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                char ch = 'a' + i;
                q.push({root->children[i], string(1, ch)});
            }
        }

        while (!q.empty()) {
            auto [node, word] = q.front();
            q.pop();

            if (node->count < k) continue;

            if (word.length() > max_word.length()) {
                max_word = word;
            }

            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    char ch = 'a' + i;
                    q.push({node->children[i], word + ch});
                }
            }
        }

        return max_word;
    }

    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n = words.size();
        vector<int> ans(n, 0);
        trieNode* root = getNode();

        for (string& word : words) {
            insert(word, root);
        }

        string longest = bfs(root, k);
        int n1 = longest.size();

        if (n1 == 0) {
            deleteTrie(root);
            return ans;
        }

        remove(longest, root);
        string sec_longest = bfs(root, k);
        int m1 = sec_longest.size();

        deleteTrie(root);

        for (int i = 0; i < n; i++) {
            if (words[i].size() < n1) {
                ans[i] = n1;
            } else {
                string temp = words[i].substr(0, n1);
                if (temp == longest) {
                    ans[i] = m1;
                } else {
                    ans[i] = n1;
                }
            }
        }

        return ans;
    }
};
