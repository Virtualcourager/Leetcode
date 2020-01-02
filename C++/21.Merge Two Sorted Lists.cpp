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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        {
            return l2;
        }
        else if(l2==NULL)
        {
            return l1;
        }
        ListNode* p= new ListNode(0);
        ListNode* ans= new ListNode(0);
        if(l1->val<l2->val)
        {
            p=l1;
            l1=l1->next;
        }
        else
        {
            p=l2;
            l2=l2->next;
        }
        p->next=NULL;
        ans=p;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                p->next=l1;
                l1=l1->next;
                p=p->next;
                p->next=NULL;
            }
            else
            {
                p->next=l2;
                l2=l2->next;
                p=p->next;
                p->next=NULL;
            }
        }
        if(l1)
        {
            p->next=l1;
        }
        else
        {
            p->next=l2;
        }
        return ans;
    }
};
