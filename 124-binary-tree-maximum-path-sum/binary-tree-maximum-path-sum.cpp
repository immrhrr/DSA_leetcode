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
    int ans;
    int solve(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        int left_right_mein_se_ek=max(l,r)+root->val;
        int only_root=root->val;
        int yahi_pe_answer=l+r+root->val;
        ans=max({left_right_mein_se_ek,only_root,yahi_pe_answer,ans});
        return max(left_right_mein_se_ek,only_root);
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        solve(root);
        return ans;

        
    }
};