class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {


        ListNode* front = new ListNode(0, head);

        unordered_map<int, ListNode*> prefix;

        int prefixSum = 0;

        ListNode* current = front;

        while (current != nullptr) {
            prefixSum += current->val;

            prefix[prefixSum] = current;

            current = current->next;
        }

        prefixSum = 0;
        current = front;

        while (current != nullptr) {
            prefixSum+=current->val;
            current->next = prefix[prefixSum]->next;

            current = current->next;
        }

        return front->next;
    }
};