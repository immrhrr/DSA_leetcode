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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;

        while (!q.empty()) {
            int n = q.size(); // Number of nodes at the current level
            long long temp = 0; // Sum of values at the current level

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp += curr->val;

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            // Compute the average and add to the result
            ans.push_back(static_cast<double>(temp) / n);
        }

        return ans;
    }
};
