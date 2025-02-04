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
    void find(TreeNode* root,int&low,int&high,int&ans){
        if(root==NULL){
            return ;
        }
        if(root->val>low&&root->val>high){
            find(root->left,low,high,ans);
        }
         else if(root->val<low&&root->val<high){
            find(root->right,low,high,ans);
        }
        else {
            find(root->left,low,high,ans);
            ans+=root->val;
            find(root->right,low,high,ans);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        find(root,low,high,ans);
        return ans;
    }
};