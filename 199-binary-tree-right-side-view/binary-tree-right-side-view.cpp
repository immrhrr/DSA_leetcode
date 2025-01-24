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
    void rightview(TreeNode*root,vector<int>&ans,int level){
        if(root==NULL){
            return ;
        }
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        rightview(root->right,ans,level+1);
        rightview(root->left,ans,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>ans;
        // if(root==NULL){
        //     return ans;
        // }
        // int level=0;
        // rightview(root,ans,level);
        // return ans;

         if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->val);
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->left){
                    q.push(curr->left);
                }
                 
               
            }
        }
        return ans;
        
    }
};