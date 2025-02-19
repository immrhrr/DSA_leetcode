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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        if(head->next==NULL){
            return head;
        }
        while(temp){
            cnt++;
            temp=temp->next;
        }
        int ind;
        ind=cnt/2 +1;
        temp=head;
        while(ind>1){
            temp=temp->next;
            ind--;
        }
        return temp;
        
    }
};