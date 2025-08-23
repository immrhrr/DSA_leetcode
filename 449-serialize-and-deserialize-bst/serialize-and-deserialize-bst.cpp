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
    // Encodes a BST to a single string.
    string serialize(TreeNode* root) {
        string result;
        preorder(root, result);
        return result;
    }

    // Decodes your encoded data to BST.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        vector<int> values;
        string val;
        while (ss >> val) {
            values.push_back(stoi(val));
        }

        int index = 0;
        return build(values, index, INT_MIN, INT_MAX);
    }

private:
    // Helper for preorder traversal
    void preorder(TreeNode* root, string &result) {
        if (!root) return;
        result += to_string(root->val) + " ";
        preorder(root->left, result);
        preorder(root->right, result);
    }

    // Helper to rebuild tree using bounds
    TreeNode* build(vector<int>& values, int &index, int lower, int upper) {
        if (index == values.size()) return nullptr;
        int val = values[index];
        if (val < lower || val > upper) return nullptr;

        TreeNode* root = new TreeNode(val);
        index++;
        root->left = build(values, index, lower, val);
        root->right = build(values, index, val, upper);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
