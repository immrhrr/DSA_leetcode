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
    unordered_map<long long,int>mp;
    void func(TreeNode*root,int&target,int&ans,long long temp){
        if(root==NULL){
            return;
        }
        temp+=root->val;
        if(temp==target){
            ans++;
        }
        if(mp.find(temp-target)!=mp.end()){
            ans+=mp[temp-target];
        }
        mp[temp]++;
        func(root->left,target,ans,temp);
        func(root->right,target,ans,temp);
        mp[temp]--;
        if(mp[temp]==0){
            mp.erase(temp);
        }
    }
    int pathSum(TreeNode* root, int target) {
        int ans=0;
        long long temp=0;
        func(root,target,ans,temp);
        return ans;
        
    }
};