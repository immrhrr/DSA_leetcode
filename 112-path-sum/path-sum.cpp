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
    bool solve(TreeNode*root,int&t,int curr){
        if(!root)return false;
        if(!root->left&&!root->right){
            return t==curr+root->val;
        }
        bool l=solve(root->left,t,curr+root->val);
        if(l)return l;
        bool r=solve(root->right,t,curr+root->val);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int t) {
        if(!root)return false;
        int curr=0;
        return solve(root,t,curr);
        
    }
};