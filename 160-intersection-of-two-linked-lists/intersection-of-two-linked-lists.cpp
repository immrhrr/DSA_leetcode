/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int n1=0;
       int n2=0;
       ListNode* temp1=head1;
       ListNode* temp2=head2;
       while(temp1){
           n1++;
           temp1=temp1->next;
       }
       while(temp2){
           n2++;
           temp2=temp2->next;
       }
       //checkl which is bigger list
       //list1 is bigger
       int extra=n2-n1;
       if(n1>=n2){
           extra=n1-n2;
           
       }
       //extra node ko pehle cover kro
       ListNode* temp=head2;
       if(n1>=n2){
           temp=head1;
       }
       while(extra>0){
           temp=temp->next;
           extra--;
       }
       ListNode* newtemp=head1;
       if(n1>=n2){
           newtemp=head2;
       }
       while(temp&&newtemp){
           if(temp==newtemp){
               return temp;
           }
           temp=temp->next;
           newtemp=newtemp->next;
       }
       return NULL;
       
    }
};