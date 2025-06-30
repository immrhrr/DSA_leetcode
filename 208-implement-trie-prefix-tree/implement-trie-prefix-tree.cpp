class Trie {
public:
    struct trieNode{
        bool is_end;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode=new trieNode();
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        newNode->is_end=false;
        return newNode;
    }
    trieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=getNode();
            }
            crawl=crawl->children[idx];
        }
        crawl->is_end=true;
    }
    
    bool search(string word) {
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl=crawl->children[idx];
        }
        if(crawl&&crawl->is_end)
        return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl=root;
        for(char ch:prefix){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl=crawl->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */