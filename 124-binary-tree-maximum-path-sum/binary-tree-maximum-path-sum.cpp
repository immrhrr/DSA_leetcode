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
    int find(TreeNode*root,int&ans){
        if(root==NULL){
            return 0;
        }
        int l=0;
        int r=0;
        l=max(0,find(root->left,ans));
        r=max(find(root->right,ans),0);
        ans=max(root->val+l+r,ans);
        return max(l,r)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        find(root,ans);
        return ans;
    }
};