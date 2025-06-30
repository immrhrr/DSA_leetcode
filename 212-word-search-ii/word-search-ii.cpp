class Solution {
public:
    struct trieNode {
        string word;
        bool is_end;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        newNode->word = "";
        newNode->is_end = false;
        return newNode;
    }

    void insert(string& word, trieNode* root) {
        trieNode* crawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (crawl->children[idx] == NULL) {
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->is_end = true;
        crawl->word = word;
    }

    vector<int> h = {1, 0, -1, 0};
    vector<int> v = {0, -1, 0, 1};

    void search(vector<vector<char>>& board, int r, int c, trieNode* root, vector<string>& ans, vector<vector<bool>>& vis) {
        int n = board.size();
        int m = board[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c]) return;

        char ch = board[r][c];
        int idx = ch - 'a';
        if (root->children[idx] == NULL) return;

        vis[r][c] = true;
        root = root->children[idx];
        if (root->is_end) {
            ans.push_back(root->word);
            root->is_end = false;  // to avoid duplicate words
        }

        for (int i = 0; i < 4; i++) {
            int nrow = r + h[i];
            int ncol = c + v[i];
            search(board, nrow, ncol, root, ans, vis);
        }

        vis[r][c] = false; // backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trieNode* root = getNode();
        for (string& word : words) {
            insert(word, root);
        }

        int row = board.size();
        int col = board[0].size();
        vector<string> ans;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                search(board, i, j, root, ans, vis);
            }
        }

        return ans;
    }
};
