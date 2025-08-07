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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int>ans;
        queue<TreeNode*>q;
        TreeNode* curr=NULL;
        q.push(root);
        while(!q.empty()){
            int m=q.size();
            ans.push_back(q.front()->val);
            while(m--){
                curr=q.front();
                q.pop();
                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->left){
                    q.push(curr->left);
                }
            }
        }
        return ans;
        
    }
};