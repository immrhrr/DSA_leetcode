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
    void solve(TreeNode*root,int&temp){
        if(!root)return;
        //right node left
        solve(root->right,temp);
        temp=temp+root->val;
        root->val=temp;
        solve(root->left,temp);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        int temp=0;
        solve(root,temp);
        return root;
    }
};