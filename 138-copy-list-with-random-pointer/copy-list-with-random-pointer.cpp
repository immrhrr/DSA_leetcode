/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        unordered_map<Node*,Node*>mp;
        Node* head_copy=new Node(head->val);
        Node* temp_head=head;
        Node* temp_copy=head_copy;
        mp[head]=head_copy;
        while(head->next){
            head_copy->next=new Node(head->next->val);
            mp[head->next]=head_copy->next;
            head=head->next;
            head_copy=head_copy->next;
        }
        head=temp_head;
        head_copy=temp_copy;
        while(head){
            head_copy->random=mp[head->random];
            head=head->next;
            head_copy=head_copy->next;
        }
        return temp_copy;
        
    }
};