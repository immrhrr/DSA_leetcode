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
        if(list1==NULL){
            return list2;
        }
         if(list2==NULL){
            return list1;
        }
        // creating dummy node
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (list1 && list2) {
            // list1 ka data is bigger than t2 ka data
            if (list1->val > list2->val) {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
            // list2 ka data is bigger than or equal to t1 ka data
            else {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
        }
        //lest1 has nodes left
        if(list1){
            tail->next = list1;
        }
        //list2 has nodes left
         if(list2){
            tail->next = list2;
        }
        //remove dummy variables
        head = head->next;
        return head;
    }
};