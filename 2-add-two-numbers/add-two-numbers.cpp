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
    void Reverse(ListNode*& head) {  // Pass by reference
        ListNode* past = NULL;
        ListNode* future = NULL;
        ListNode* present = head;
        while (present) {
            future = present->next;
            present->next = past;
            past = present;
            present = future;
        }
        head = past;  // Update head
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse both lists
        // Reverse(l1);
        // Reverse(l2);

        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;

        while (l1 || l2 || carry) {  // Handle all cases
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        ans = ans->next;
       // Reverse(ans);  // Reverse final result
        return ans;
    }
};
