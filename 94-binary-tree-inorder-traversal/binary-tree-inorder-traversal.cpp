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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<TreeNode*>st;
        stack<bool>vis;
        st.push(root);
        vis.push(0);
        vector<int>ans;
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            int flag=vis.top();
            vis.pop();
            if(flag==1){
                ans.push_back(curr->val);
            }
            else{
                if(curr->right){
                     st.push(curr->right);
                     vis.push(0);

                }
                st.push(curr);
                vis.push(1);

                if(curr->left){
                    st.push(curr->left);
                     vis.push(0);
                } 
            }
        }
        return ans;
    }
};