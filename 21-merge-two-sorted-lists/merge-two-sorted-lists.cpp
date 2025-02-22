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
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        // creating dummy node
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (t1 && t2) {
            // t1 ka data is bigger than t2 ka data
            if (t1->val > t2->val) {
                tail->next = t2;
                tail = tail->next;
               
                t2 = t2->next;
            }
            // t2 ka data is bigger than or equal to t1 ka data
            else {
                tail->next = t1;
                tail = tail->next;
               
                t1 = t1->next;
            }
        }
        if(t1){
            tail->next = t1;
        }
         if(t2){
            tail->next = t2;
        }
        head = head->next;
        return head;
    }
};