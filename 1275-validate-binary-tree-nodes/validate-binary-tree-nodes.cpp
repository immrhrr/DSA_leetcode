class Solution {
public:
    int find(int a,vector<int>&parent){
        if(parent[a]==a)return a;
        return parent[a]=find(parent[a],parent);
    }
    bool Union(int a,int b,vector<int>&parent,int&comp){
        if(find(b,parent)!=b)return false;
        if(find(a,parent)==b)return false;
        comp--;
        parent[b]=a;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>parent(n,0);
        iota(parent.begin(),parent.end(),0);
        int comp=n;
        for(int i=0;i<n;i++){
            int lc=leftChild[i];
            int rc=rightChild[i];
            int node=i;
            if(lc!=-1&&Union(node,lc,parent,comp)==false){
                return false;
            }
            if(rc!=-1&&Union(node,rc,parent,comp)==false){
                return false;
            }
        }
        return comp==1;
        
    }
};