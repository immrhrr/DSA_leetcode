/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function that returns a pair: {depth of subtree, LCA node for that depth}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) {
            return {0, nullptr};
        }

        pair<int, TreeNode*> left = dfs(root->left);
        pair<int, TreeNode*> right = dfs(root->right);

        // Case 1: Both subtrees have the same depth.
        // This means the deepest nodes are split across both sides, so the current
        // 'root' is their Lowest Common Ancestor.
        if (left.first == right.first) {
            return {left.first + 1, root};
        }
        
        // Case 2: Left subtree is deeper.
        // The deepest nodes (and their LCA) must be in the left subtree.
        else if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        
        // Case 3: Right subtree is deeper.
        // The deepest nodes (and their LCA) must be in the right subtree.
        else {
            return {right.first + 1, right.second};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};