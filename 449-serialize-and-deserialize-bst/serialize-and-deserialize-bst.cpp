/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a BST to a single string (preorder traversal).
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    void preorder(TreeNode* root, string &s) {
        if (!root) return;
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Decodes your encoded data to BST.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string str;
        vector<int> vals;

        while (getline(ss, str, ',')) {
            if (!str.empty()) vals.push_back(stoi(str));
        }

        int idx = 0;
        return build(vals, idx, INT_MIN, INT_MAX);
    }

    TreeNode* build(vector<int> &vals, int &idx, int low, int high) {
        if (idx >= vals.size()) return NULL;
        int val = vals[idx];
        if (val < low || val > high) return NULL;

        TreeNode* node = new TreeNode(val);
        idx++;
        node->left = build(vals, idx, low, val);
        node->right = build(vals, idx, val, high);
        return node;
    }
};

// Usage
// Codec ser, deser;
// string tree = ser.serialize(root);
// TreeNode* ans = deser.deserialize(tree);
