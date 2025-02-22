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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* present=head->next;
        ListNode* past= head;
        while(past&&present){
            swap(past->val,present->val);
            if(present->next==NULL){
                break;
            }
            past=present->next;
            present=past->next;
        }
        return head;

    }
};