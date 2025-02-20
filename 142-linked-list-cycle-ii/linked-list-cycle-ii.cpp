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
    ListNode *detectCycle(ListNode *head) {
        //nodes-length of cycle
        //linked list does not exists or there is only one node
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        //check if cycle exists or not first
        ListNode* slow=head;
        ListNode* fast=head;
       // bool cycle=false;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                //cycle exists
        //we know that distance from slow and head is same to the first node where cycle starts
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        //return slow or fast
        return slow;
            }
        }
        //cycle does not exists
            return NULL; 
    }
};