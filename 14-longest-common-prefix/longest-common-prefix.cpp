class Solution {
public:
    struct trieNode {
        trieNode* children[26];
        int cnt = 0;
    };

    trieNode* getNode() {
        trieNode* node = new trieNode();
        for (int i = 0; i < 26; ++i) {
            node->children[i] = nullptr;
        }
        return node;
    }

    void buildTrie(trieNode* root, const string& s) {
        trieNode* crawl = root;
        for (char ch : s) {
            int index = ch - 'a';
            if (!crawl->children[index]) {
                crawl->children[index] = getNode();
            }
            crawl = crawl->children[index];
            crawl->cnt++;
        }
    }

    void search(trieNode* root, string& temp, int n) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] && root->children[i]->cnt == n) {
                temp += (char)('a' + i);
                search(root->children[i], temp, n);  // continue the only valid path
                break;  // only one path will be valid, so break after first
            }
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        trieNode* root = getNode();
        for (const string& s : strs) {
            buildTrie(root, s);
        }

        int n = strs.size();
        string ans = "";
        search(root, ans, n);
        return ans;
    }
};
