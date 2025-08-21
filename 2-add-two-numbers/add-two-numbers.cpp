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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        int sum = 0;
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* ans = head;
        while (t1 || t2) {
            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->val;
                 t2 = t2->next;
            }
            ListNode* temp = new ListNode(sum % 10);
            head->next = temp;
            head = head->next;
            sum = sum / 10;
        }
        if (sum > 0) {
            ListNode* temp = new ListNode(sum % 10);
            head->next = temp;
            head = head->next;
        }
        return ans->next;
    }
};