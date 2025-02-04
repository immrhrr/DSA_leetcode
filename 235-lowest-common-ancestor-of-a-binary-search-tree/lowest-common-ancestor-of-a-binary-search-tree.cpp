/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* func(TreeNode* root,int&x,int&y){
        if(root==NULL){
            return root;
        }
        if(root->val>x&&root->val>y){
            return func(root->left,x,y);
        }

         else if(root->val<x&&root->val<y){
            return func(root->right,x,y);
        }
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x=p->val;
        int y=q->val;
        return func(root,x,y);
    }
};