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
    void inorder(TreeNode* root, vector<int>& temp) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        inorder(root1, a);
        inorder(root2, b);
        int n1 = a.size();
        int n2 = b.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < n1 && j < n2) {
            if (a[i] == b[j]) {
                ans.push_back(a[i]);
                ans.push_back(b[j]);
                i++;
                j++;
            } else if (a[i] > b[j]) {
                ans.push_back(b[j]);
                j++;
            } else {
                ans.push_back(a[i]);
                i++;
            }
        }
        while (i < n1) {
            ans.push_back(a[i]);
            i++;
        }
        while (j < n2) {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};