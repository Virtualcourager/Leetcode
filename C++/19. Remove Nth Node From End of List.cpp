/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* i=new ListNode(0);
        ListNode* j=new ListNode(0);
        i=head,j=head;
        if(j==NULL)
            return NULL;
        for(int i=0;i<n;i++)
        {
            j=j->next;
        }
        if(j==NULL)
            return head->next;
        while(j->next!=NULL)
        {
            j=j->next;
            i=i->next;
        }
        i->next=i->next->next;
        return head;
    }
};
