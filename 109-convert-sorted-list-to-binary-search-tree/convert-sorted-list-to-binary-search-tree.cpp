/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(vector<int>&temp,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=start+(end-start+1)/2;
        TreeNode* root=new TreeNode(temp[mid]);
        root->left=build(temp,start,mid-1);
        root->right=build(temp,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
       
        return build(temp,0,temp.size()-1);
    }
};