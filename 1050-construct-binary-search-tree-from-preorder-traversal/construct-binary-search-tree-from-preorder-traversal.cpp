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
    TreeNode* bst(vector<int>&preorder,int lower, int upper,int&index){
        if(index==preorder.size()||preorder[index]<lower||preorder[index]>upper){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index++]);
        root->left=bst(preorder,lower,root->val,index);
        root->right=bst(preorder,root->val,upper,index);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int lower=INT_MIN;
        int upper=INT_MAX;
        int index=0;
        return bst(preorder,lower,upper,index);
    }
};