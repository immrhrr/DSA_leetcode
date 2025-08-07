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
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int inStart,int inEnd,int ind, unordered_map<int,int>&mp){
        if(inStart>inEnd)return NULL;
        TreeNode* root=new TreeNode(preorder[ind]);
        int pos=mp[preorder[ind]];
        root->left=build(preorder,inorder,inStart,pos-1,ind+1,mp);
        root->right=build(preorder,inorder,pos+1,inEnd,ind+(pos-inStart)+1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,n-1,0,mp);
    }
};