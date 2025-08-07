/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int inStart,
                    int inEnd, int ind, unordered_map<int, int>& mp) {
        if (inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[ind]);
        int pos = mp[postorder[ind]];
        root->right = build(postorder, inorder, pos + 1, inEnd,
                            ind - 1, mp);
        root->left = build(postorder, inorder, inStart, pos - 1, ind - (inEnd - pos) - 1, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return build(postorder, inorder, 0, n - 1, n-1, mp);
    }
};