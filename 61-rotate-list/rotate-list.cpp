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
    ListNode* rotateRight(ListNode* head, int k) {
        
        //no rotation or there is only one node so any rotation will nnot change it
        if(!head||k==0||head->next==NULL){
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        //minimal number of rotation
        k=k%cnt;
        if(k==0){
            return head;
        }
        //random number of rotaion
        temp=head;
        int curr=0;
        while(temp){
            curr++;
            if(curr==cnt-k){
                break;
            }
            temp=temp->next;
        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        ListNode *tail=newhead;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=head;
        return newhead;
    }
};