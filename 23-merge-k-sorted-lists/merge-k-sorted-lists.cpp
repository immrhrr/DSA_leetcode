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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
              int val=lists[i]->val;
              pq.push({val,lists[i]});
            }
            
        }
        ListNode* node=new ListNode(-1);
        ListNode* head=node;
        while(!pq.empty()){
            ListNode* curr=pq.top().second;
            node->next=curr;
            node=node->next;
            pq.pop();
            if(curr->next){
                pq.push({curr->next->val,curr->next});
            }
        }
        return head->next;
        
    }
};