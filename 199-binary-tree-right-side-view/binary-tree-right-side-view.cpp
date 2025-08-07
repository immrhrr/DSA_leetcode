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
    void solve(TreeNode*curr,vector<int>&ans,int level){
        if(!curr)return;
        if(level-1==ans.size())
        ans.push_back(curr->val);
        solve(curr->right,ans,level+1);
        solve(curr->left,ans,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int>ans;
        solve(root,ans,1);
        return ans;
    }
};