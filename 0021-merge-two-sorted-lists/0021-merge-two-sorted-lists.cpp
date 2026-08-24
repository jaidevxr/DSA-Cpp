class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = new ListNode(0);
        ListNode* n = head;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val < list2->val) {
                n->next = list1;
                list1 = list1->next;
            }
            else {
                n->next = list2;
                list2 = list2->next;
            }

            n = n->next;
        }

        if (list1 != NULL)
            n->next = list1;
        else
            n->next = list2;

        return head->next;
    }
};