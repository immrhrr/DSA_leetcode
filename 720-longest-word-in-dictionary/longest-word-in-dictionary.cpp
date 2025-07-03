class Solution {
public:
    struct trieNode{
        bool is_end;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode=new trieNode();
        for(int i=0;i<26;i++){
            newNode->children[i]=nullptr;
        }
        newNode->is_end=false;
        return newNode;
    }

    void insert(string&word,trieNode*root){
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!crawl->children[idx]){
                crawl->children[idx]=getNode();
            }
            crawl=crawl->children[idx];
        }
        crawl->is_end=true;
    }
    static bool comp(const string&s1,const string&s2){
        return s1.size()<s2.size();
    }
    bool check(string&word,trieNode*root){
        trieNode* crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!crawl->children[idx]){
                return false;
            }
            crawl=crawl->children[idx];
            if(!crawl->is_end){
                return false;
            }
        }
        return crawl->is_end;
    }
    string longestWord(vector<string>& words) {
        trieNode* root=getNode();
        sort(words.begin(),words.end(),comp);
        string ans="";
        for(string word:words){
            insert(word,root);
        }
        for(int i=words.size()-1;i>=0;i--){
            if(check(words[i],root)){
                if(ans.size()<words[i].size()){
                    ans=words[i];
                }
                else if(ans.size()==words[i].size()){
                    ans=min(ans,words[i]);
                }
            }
        }
        return ans;
        
    }
};