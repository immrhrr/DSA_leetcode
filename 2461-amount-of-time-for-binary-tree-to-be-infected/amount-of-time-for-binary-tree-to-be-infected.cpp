/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>>adj;
    void make_graph(TreeNode*root,int parent){
        if(!root)return;
        if(parent!=-1){
            adj[root->val].push_back(parent);
        }
        if(root->left){
            adj[root->val].push_back(root->left->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
        }
        make_graph(root->left,root->val);
        make_graph(root->right,root->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        make_graph(root,-1);
        queue<pair<int,int>>q;
        q.push({start,-1});
        int time=0;
        
        while(!q.empty()){
            int m=q.size();
            time++;
            while(m--){
                int curr=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(int i=0;i<adj[curr].size();i++){
                    int ngbr=adj[curr][i];
                    if(ngbr==parent)continue;
                    q.push({ngbr,curr});
                }
            }
        }
        return time-1;
    }
};