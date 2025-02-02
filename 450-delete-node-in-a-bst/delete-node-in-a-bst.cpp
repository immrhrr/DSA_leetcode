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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //key does not exists
        if(root==NULL){
            return root;
        }
        //finding
        if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        //finding
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        //mil gya
        else{
            //leaf node hai
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            //left child hai
            if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            //right child hai
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //both child hai bro
            else{
                TreeNode* child=root->left;
                TreeNode* parent=root;
                while(child->right){
                    parent=child;
                    child=child->right;
                }
                //parent ==root
                if(parent==root){
                    child->right=root->right;
                    delete root;
                    return child;
                }
                //parent not equal to child
                else{
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }

        }
    }
};