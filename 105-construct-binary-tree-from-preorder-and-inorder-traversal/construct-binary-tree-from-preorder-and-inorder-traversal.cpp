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
     TreeNode* Tree(vector<int>&inorder,vector<int>&preorder,int inStart,
  int inEnd,int index,unordered_map<int,int>&mp){
      if(inStart>inEnd){
          return NULL;
      }
      TreeNode* root=new TreeNode(preorder[index]);
      int position=mp[preorder[index]];
      root->left=Tree(inorder,preorder,inStart,position-1,index+1,mp);
      root->right=Tree(inorder,preorder,position+1,inEnd,index+(position-inStart)+1,mp);
      return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0){
           return NULL;
       }
       unordered_map<int,int>mp;
       for(int i=0;i<inorder.size();i++){
           mp[inorder[i]]=i;
       }
       return Tree(inorder,preorder,0,inorder.size()-1,0,mp);
    }
};