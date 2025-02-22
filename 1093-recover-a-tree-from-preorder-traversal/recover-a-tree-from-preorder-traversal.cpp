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
    TreeNode* solve(string&s,int&i,int d){
        int j=i;
        int n=s.size();
        //finding the number of dash
        while(j<n&&s[j]=='-'){
            j++;
        }
        int dash=j-i;
        // we are at higher depth than required one
        //so need to return back
        if(dash!=d){
            return NULL;
        }
        //already traversed
        i=j;
        int num=0;
        //finding the value to insert
        while(i<n&&isdigit(s[i])){
            num=(num*10)+(s[i]-'0');
            i++;
        }
        //constructing the tree
        TreeNode* root=new TreeNode(num);
        root->left=solve(s,i,d+1);
        root->right=solve(s,i,d+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string s) {
        int i=0;
        int d=0;
        return solve(s,i,d);
        
    }
};