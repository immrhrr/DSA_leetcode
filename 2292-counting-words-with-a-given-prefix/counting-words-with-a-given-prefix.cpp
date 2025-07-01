class Solution {
public:
    struct trieNode{
        int cnt;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode=new trieNode();
        for(int i=0;i<26;i++){
            newNode->children[i]=nullptr;
        }
        newNode->cnt=0;
        return newNode;
    }
    void insert(string&word,trieNode*root){
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!crawl->children[idx]){
                crawl->children[idx]=getNode();
            }
            crawl->cnt++;
            crawl=crawl->children[idx];
        }
        crawl->cnt++;
    }
    int search(string&word,trieNode*root){
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!crawl->children[idx]){
                return 0;
            }
            crawl=crawl->children[idx];
        }
        return crawl->cnt;
    }
    int prefixCount(vector<string>& words, string pref) {
        trieNode* root=getNode();
        for(string word:words){
            insert(word,root);
        }
        return search(pref,root);
    }
};