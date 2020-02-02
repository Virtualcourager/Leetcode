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
        if(head==NULL)
            return NULL;
        Node* node=new Node(0);
        Node*cur=new Node(0);
        Node*pre=new Node(0);
        cur=head;
        node->val=cur->val;
        unordered_map<Node*,Node*> mp;
        mp[cur]=node;
        cur=cur->next;
        pre=node;
        while(cur!=NULL)
        {
            Node* n=new Node(0);
            n->val=cur->val;
            pre->next=n;
            mp[cur]=n;
            cur=cur->next;
            pre=n;
        }
        pre->next=NULL;
        pre=node;
        cur=head;
        mp[NULL]=NULL;
        while(cur!=NULL)
        {
            pre->random=mp[cur->random];
            cur=cur->next;
            pre=pre->next;
        }
        return node;
    }
};
