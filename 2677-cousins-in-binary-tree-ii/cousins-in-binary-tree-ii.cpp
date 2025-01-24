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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        queue<TreeNode*>q;
        root->val=0;
        q.push(root);
        long long level_sum=root->val;
        while(!q.empty()){
            int n=q.size();
            long long temp=0;
            
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                long long sib=0;
                if(curr->left){
                    sib+=curr->left->val;
                }
                if(curr->right){
                    sib+=curr->right->val;
                }
               temp+=sib;
                if(curr->left){
                    curr->left->val=sib;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=sib;
                    q.push(curr->right);
                }
                curr->val=level_sum-curr->val;
            }
            level_sum=temp;
            
        }
        return root;
    }
};