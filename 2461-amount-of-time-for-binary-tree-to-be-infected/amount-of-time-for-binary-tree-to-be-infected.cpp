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
    int burn(TreeNode* root,int &start,int &timer,TreeNode* &burn_node){
        if(root==NULL){
            return 0;
        }
        if(root->val==start){
            burn_node=root;
            return -1;
        }
        int left=burn(root->left,start,timer,burn_node);
        int right=burn(root->right,start,timer,burn_node);
        if(left<0){
            timer=max(timer,abs(left)+right);
            return left-1;
        }
        if(right<0){
            timer=max(timer,abs(right)+left);
            return right-1;
        }
        return 1+max(left,right);
    }
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    int amountOfTime(TreeNode* root, int start) {
        int timer=0;
        TreeNode* burn_node=NULL;
        burn(root,start,timer,burn_node);
        int temp=height(burn_node);
        return max(timer,temp-1);
    }
};