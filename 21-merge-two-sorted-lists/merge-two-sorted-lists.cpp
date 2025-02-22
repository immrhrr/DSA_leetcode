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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(t1&&t2){
            //t1 bigger than t2 ka data
            if(t1->val>t2->val){
                tail->next=new ListNode(t2->val);
                 t2=t2->next;
            }
            else{
                tail->next=new ListNode(t1->val);
                 t1=t1->next;
            }
           
           
            tail=tail->next;
        }
        while(t1){
             tail->next=new ListNode(t1->val);
             t1=t1->next;
             tail=tail->next;
        }
        while(t2){
             tail->next=new ListNode(t2->val);
             t2=t2->next;
             tail=tail->next;
        }
        head=head->next;
        return head;
    }
};