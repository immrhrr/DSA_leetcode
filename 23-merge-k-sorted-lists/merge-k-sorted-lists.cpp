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
    class compare{
        public:
        bool operator()(ListNode*a,ListNode*b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        ListNode* root=new ListNode(0);
        ListNode* temp,*tail;
        tail=root;
        while(!pq.empty()){
            temp=pq.top();
            pq.pop();
            if(temp==NULL){
                continue;
            }
            tail->next=temp;
            tail=temp;
            if(temp->next){
                pq.push(temp->next);
            }
        }
        return root->next;

    }
};