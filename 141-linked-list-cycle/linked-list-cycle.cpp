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
    bool hasCycle(ListNode *head) {
        //linked list does not exists or it has single node only
        if(head==NULL||head->next==NULL){
            return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next&&fast->next->next&&fast->next->next->next){
            slow=slow->next;
            fast=fast->next->next->next->next;
            if(fast==slow){
                return true;
            }

        }
        return false;
        
    }
};