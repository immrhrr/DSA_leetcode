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
    unordered_map<int, int> mp; // Store postorder index for quick lookup

    TreeNode* func(vector<int>& preorder, int pre_start, int pre_end, int post_start, int post_end) {
        if (pre_start > pre_end) return NULL;

        // Create the root node
        TreeNode* root = new TreeNode(preorder[pre_start]);

        // If only one node, return it
        if (pre_start == pre_end) return root;

        // Find left subtree's root in postorder
        int left_root_idx = mp[preorder[pre_start + 1]];
        int left_size = left_root_idx - post_start + 1;  // Size of left subtree

        // Recursively construct left and right subtrees
        root->left = func(preorder, pre_start + 1, pre_start + left_size, post_start, left_root_idx);
        root->right = func(preorder, pre_start + left_size + 1, pre_end, left_root_idx + 1, post_end - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            mp[postorder[i]] = i;  // Map postorder value to its index
        }
        return func(preorder, 0, n - 1, 0, n - 1);
    }
};
