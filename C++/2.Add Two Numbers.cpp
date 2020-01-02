class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
               if (l1 == NULL || l2 == NULL) {
            return NULL;
        }
        ListNode* temp = new ListNode(0);
        ListNode* result = temp;

        int value1 = 0;
        int value2 = 0;
        while (l1 != NULL && l2 != NULL) {
            value2 = (l1->val + l2->val + value1) % 10;
            value1 = (l1->val + l2->val + value1) / 10;

            temp->next = new ListNode(value2);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
            if (l1 == NULL && l2 == NULL) {
                break;
            }
            if (l1 == NULL) {
                l1 = new ListNode(0);
            }
            if (l2 == NULL) {
                l2 = new ListNode(0);
            }
        }
        if (value1 != 0) {
            temp->next = new ListNode(value1);
        }
        return result->next;
    }
};
