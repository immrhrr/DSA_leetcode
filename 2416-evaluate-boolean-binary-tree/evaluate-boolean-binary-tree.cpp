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
    bool f(TreeNode* root){
        if(root->val==1){
            return true;
        }
        if(root->val==0){
            return false;
        }
       
        bool left=f(root->left);
        bool right=f(root->right);
        if(root->val==2){
            return left||right;
        }
        if(root->val==3){
            return left&&right;
        }
        return true;
    }
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};