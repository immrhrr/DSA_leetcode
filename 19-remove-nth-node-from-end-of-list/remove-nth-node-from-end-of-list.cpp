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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=0;
        ListNode* temp=head;
        while(temp){
            total++;
            temp=temp->next;
        }
        if(n==total){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        if(n==1){
            ListNode* prev=NULL;
            temp=head;
            while(temp->next){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            delete temp;
            return head;
        }
        int ind=total-n+1;
        int cnt=1;
        temp=head;
        ListNode*prev=NULL;
        while(cnt!=ind){
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        //if(temp)
        prev->next=temp->next;
        delete temp;
        return head;

        
    }
};