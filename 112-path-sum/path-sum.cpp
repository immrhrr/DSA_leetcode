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
    bool func(TreeNode* root,int target){
         if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return target==root->val;
        }
       return func(root->left,target-root->val)||func(root->right,target-root->val);
    }
    bool hasPathSum(TreeNode* root, int target) {
        return func(root,target);
    }
};