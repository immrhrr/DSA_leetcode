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
class Solution {
public:
    void Reverse(ListNode* &head){
        if(head==NULL||head->next==NULL){
            return ;
        }
        ListNode* present=head;
        ListNode* past=NULL;
        ListNode* future=NULL;
        while(present){
            future=present->next;
            present->next=past;
            past=present;
            present=future;
        }
        head=past;
        return;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        Reverse(l1);
        Reverse(l2);
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* ans=new ListNode(0);
        ListNode* tail=ans;
        while(temp1&&temp2){
            int temp=temp1->val+temp2->val+carry;
            int digit=temp%10;
            carry=temp/10;
            tail->next=new ListNode(digit);
            temp1=temp1->next;
            temp2=temp2->next;
            tail=tail->next;
        }
        while(temp1){
            int temp=temp1->val+carry;
            int digit=temp%10;
            carry=temp/10;
            tail->next=new ListNode(digit);
            temp1=temp1->next;
            tail=tail->next;
        }
        while(temp2){
            int temp=temp2->val+carry;
            int digit=temp%10;
            carry=temp/10;
            tail->next=new ListNode(digit);
            temp2=temp2->next;
            tail=tail->next;
        }
        if(carry>0){
            tail->next=new ListNode(carry);
        }
        ans=ans->next;
        Reverse(ans);
      
        return ans;
    }
};