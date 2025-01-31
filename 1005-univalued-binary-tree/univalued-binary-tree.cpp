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
    void preorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    bool isUnivalTree(TreeNode* root) {
        vector<int>temp;
        if(root==NULL){
            return true;
        }
        preorder(root,temp);
        int n=temp.size();
        sort(temp.begin(),temp.end());
        return temp[0]==temp[n-1];
    }
};