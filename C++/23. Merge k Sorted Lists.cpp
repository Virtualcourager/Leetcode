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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        return merge(lists,0,lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists,int start,int end) {
        if(start==end)
            return lists[start];
        int mid=start+(end-start)/2;
        ListNode* left=merge(lists,start,mid);
        ListNode* right=merge(lists,mid+1,end);
        return mergesort(left,right);
    }
    ListNode* mergesort(ListNode* l,ListNode* r)
    {
        if(!l)
            return r;
        else if(!r)
            return l;
        if(l->val<r->val)
        {
            l->next=mergesort(l->next,r);
                return l;
        }
        else
        {
            r->next=mergesort(l,r->next);
                return r;
        }
    }
};
