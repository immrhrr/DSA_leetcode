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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        queue<TreeNode*>q;
        vector<int>level_sum;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            int temp=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                temp+=curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

            }
            level_sum.push_back(temp);
        }
        root->val=0;
        q.push(root);
        int level=0;
        while(!q.empty()){
           
            int n=q.size();
            for(int i=0;i<n;i++){
                int sibling_sum=0;
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    sibling_sum+=curr->left->val;
                }
                if(curr->right){
                    sibling_sum+=curr->right->val;
                }
               
                if(curr->right){
                    curr->right->val=level_sum[level+1]-sibling_sum;
                    q.push(curr->right);
                }
                if(curr->left){
                    curr->left->val=level_sum[level+1]-sibling_sum;
                    q.push(curr->left);
                }
            }
            level++;
        }
        return root;
    }
};






// class Solution {
// public:
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         if (!root) {
//             return root;
//         }

//         queue<TreeNode*> q;
//         vector<int> level_sum;

//         // Calculate the sum of values at each level
//         q.push(root);
//         while (!q.empty()) {
//             int n = q.size();
//             int temp = 0;
//             for (int i = 0; i < n; i++) {
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 temp += curr->val;

//                 if (curr->left) {
//                     q.push(curr->left);
//                 }
//                 if (curr->right) {
//                     q.push(curr->right);
//                 }
//             }
//             level_sum.push_back(temp);
//         }

//         // Replace values in the tree
//         root->val = 0; // Root's value is always 0
//         q.push(root);
//         int level = 0;

//         while (!q.empty()) {
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 // Calculate sibling sum for this node
//                 int sibling_sum = 0;
//                 if (curr->left) sibling_sum += curr->left->val;
//                 if (curr->right) sibling_sum += curr->right->val;

//                 // Update child nodes
//                 if (curr->left) {
//                     curr->left->val = level_sum[level + 1] - sibling_sum;
//                     q.push(curr->left);
//                 }
//                 if (curr->right) {
//                     curr->right->val = level_sum[level + 1] - sibling_sum;
//                     q.push(curr->right);
//                 }
//             }
//             level++;
//         }

//         return root;
//     }
// };
