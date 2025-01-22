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
    bool f(TreeNode*p,TreeNode*q){
        if(p==NULL&&q==NULL){
            return 1;
        }
        if(p==NULL||q==NULL){
            return 0;
        }
        if(p->val!=q->val){
            return 0;

        }
        return f(p->left,q->left)&&f(p->right,q->right);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p,q);
    }
};