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

class Box{
    public:
    bool bst;
    int sum;
    int min;
    int max;
    Box(int data){
        bst=true;
        sum=data;
        min=data;
        max=data;
    }
};
class Solution{
    public:
    Box* find(TreeNode* root,int&ans){
         
        //leaf node hai
        if(root->left==NULL&&root->right==NULL){
            ans=max(ans,root->val);
            return   new Box(root->val);
        }
        //only left child exists
        else if(root->right==NULL&&root->left){
            //go to left side
            Box* head=find(root->left,ans);
            //if left child is bst
            if(head->bst && head->max<root->val){
                head->sum+=root->val;
                head->max=root->val;
                ans=max(ans,head->sum);
                return head;
            }
            //left child is not bst
            else{
                head->bst=false;
                return head;
            }
            
        }
        //only right child exists
        else if(root->left==NULL&&root->right){
            //go to right size
            Box* head=find(root->right,ans);
            //if right side it bst
            if(head->bst&& head->min>root->val){
                head->sum+=root->val;
                head->min=root->val;
                ans=max(ans,head->sum);
                return head;
            }
            //if left child is not bst
            else{
                head->bst=false;
                return head;
            }
            
        }
        //both left and right child exists
        else{
            //go to both side
            Box* lhead=find(root->left,ans);
            Box* rhead=find(root->right,ans);
            //chekc for bst
            
            if(lhead->bst&&rhead->bst&&lhead->max<root->val&&rhead->min>root->val){
                Box* head=new Box(root->val);
                head->sum+=lhead->sum+rhead->sum;
                head->min=lhead->min;
                head->max=rhead->max;
                ans=max(ans,head->sum);
                return head;
            }
           // if not bst
            else{
                lhead->bst=false;
                 return lhead;
            }
           
        }
      
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
  int maxSumBST(TreeNode* root)
    {
        if(root==NULL){
            return 0;
        }
    	int ans=INT_MIN;
    	find(root,ans);
    	return max(ans,0);
    }
};
