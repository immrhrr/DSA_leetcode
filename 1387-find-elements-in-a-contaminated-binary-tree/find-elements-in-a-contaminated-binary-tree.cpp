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
class FindElements {
public:
    TreeNode* head; // Store the root

    // Constructor to recover the tree
    FindElements(TreeNode* root) {
        head = root;
        recoverTree(root, 0);
    }

    // Function to recover the tree
    void recoverTree(TreeNode* node, int val) {
        if (!node) return;
        node->val = val;
        if (node->left) recoverTree(node->left, 2 * val + 1);
        if (node->right) recoverTree(node->right, 2 * val + 2);
    }

   

    // Function to find if the target exists in the recovered tree
    bool find(int target) {
       

        TreeNode* temp = head;
        stack<int> st;
        st.push(target);

        // Compute path from target to root
        int parent = (target - 1) / 2;
        while (parent > 0) {
            st.push(parent);
            if (parent == 0) break;
            parent = (parent - 1) / 2;
        }

        // Traverse from root following the stored path
        while (!st.empty()) {
            int value = st.top();
            st.pop();

            

            if (value % 2 == 0) {

                temp = temp->right; 
                if(temp==NULL){
                    return false;
                }
              
            } else {
                temp = temp->left;  // Move to left child
                 if(temp==NULL){
                    return false;
                }
            }
        }
        return true; // Successfully reached target node
    }
};



/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */