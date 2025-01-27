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
    TreeNode* Tree(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int index,unordered_map<int,int>&mp){
        if(inStart>inEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[index]);
        int position=mp[postorder[index]];
       
        root->left=Tree(inorder,postorder,inStart,position-1,index-(inEnd-position)-1,mp);
         root->right=Tree(inorder,postorder,position+1,inEnd,index-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(n==0){
            return NULL;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int inStart=0;
        int inEnd=n-1;
        int index=n-1;

        
        return Tree(inorder,postorder,inStart,inEnd,index,mp);
    }
};