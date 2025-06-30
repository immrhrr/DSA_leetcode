class Solution {
public:
    struct trieNode{
        int countP;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode=new trieNode();
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        newNode->countP=0;
        return newNode;
    }
    void insert(string&word, trieNode*root){
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=getNode();
            }
            crawl->children[idx]->countP+=1;
            crawl=crawl->children[idx];
        }
    }
    int getScore(string&word,trieNode*root){
        int score=0;
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            score+=crawl->children[idx]->countP;
            crawl=crawl->children[idx];
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        trieNode* root=new trieNode();
        int n=words.size();
        for(string word:words){
            insert(word,root);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=getScore(words[i],root);
        }
        return ans;
    }
};