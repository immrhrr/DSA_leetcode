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
    bool check_parent(TreeNode* root, int x, int y) {
        if(!root){
            return false;
        }
        if (root->left &&root->right) {
            if ((root->left->val == x && root->right->val == y) ||
            (root->left->val == y && root->right->val == x)) {
            return true;
        }
        }
       
        return check_parent(root->left, x, y) || check_parent(root->right, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        // Level-order traversal to determine levels
        queue<TreeNode*> q;
        q.push(root);
        //we are initialising both level1 and level2 with different values 
        // so that if x,y does not exists we can have different levels clearly
        int level = 0, level1 = -1, level2 = -3;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->val == x) {
                    level1 = level;
                } else if (curr->val == y) {
                    level2 = level;
                }

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            level++;
        }

        // Nodes must be on the same level
        if (level1 != level2) {
            return false;
        }

        // Nodes must not have the same parent
        if (check_parent(root, x, y)) {
            return false;
        }

        return true;
    }
};