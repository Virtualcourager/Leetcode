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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* cur=new ListNode(0);
        ListNode* pre=new ListNode(0);
        ListNode* nxt=new ListNode(0);
        cur=head->next;
        pre=head;
        while(cur!=NULL)
        {
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        head->next=NULL;
        return pre;
    }
};
