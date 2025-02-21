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
    unordered_set<int>st;
    void dfs(TreeNode* root,int temp){
        root->val=temp;
        st.insert(temp);
        if(root->left){
            dfs(root->left,2*root->val+1);
        }
        if(root->right){
            dfs(root->right,2*root->val+2);
        }
    }
    FindElements(TreeNode* root) {
        st.clear();
        dfs(root,0);
        
        
    }
    
    bool find(int target) {
        return st.count(target);
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */