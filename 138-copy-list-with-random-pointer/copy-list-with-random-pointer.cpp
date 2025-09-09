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
        if(head==NULL)return head;
        unordered_map<Node*,Node*>mp;
        Node* temp_node=head;
        Node* temp_copy=new Node(head->val);
        Node* temp_head=temp_copy;
        mp[head]=temp_copy;
        while(head->next){
            temp_copy->next=new Node(head->next->val);
            mp[head->next]=temp_copy->next;
            head=head->next;
            temp_copy=temp_copy->next;
        }
        head=temp_node;
        temp_copy=temp_head;
        while(head){
            temp_copy->random=mp[head->random];
            temp_copy=temp_copy->next;
            head=head->next;
        }
        return temp_head;
        
    }
};

