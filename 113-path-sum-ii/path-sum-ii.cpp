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
    vector<vector<int>>ans;
    void fill(TreeNode* root,vector<int>temp,int sum,int &targetSum){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
            }
        }
        fill(root->left,temp,sum,targetSum);
        fill(root->right,temp,sum,targetSum);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return ans;
        }
        vector<int>temp;
        int sum=0;
        fill(root,temp,sum,targetSum);
        return ans;
    }
};