class Solution {
public:
    struct trieNode {
        bool is_end;
        string word;
        trieNode* children[26];
    };
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        newNode->is_end = false;
        newNode->word = "";
        return newNode;
    }
    void insert(string& word, trieNode* root) {
        trieNode* crawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawl->children[idx]) {
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->is_end = true;
        crawl->word = word;
    }
    string search(string& word, trieNode* root) {
        trieNode* crawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawl->children[idx]) {
                return word;
            }
            crawl = crawl->children[idx];
            if (crawl->is_end) {
                return crawl->word;
            }
            
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentences) {
        trieNode* root = getNode();
        for (string word : dictionary) {
            insert(word, root);
        }
        string ans;
        string temp;
        for(int i=0;i<sentences.size();i++){
            if(sentences[i]==' '){
                ans+=search(temp,root);
                ans+=" ";
                temp="";
            }
            else{
                 temp+=sentences[i];
            }

        }
        ans+=search(temp,root);
        return ans;
    }
};