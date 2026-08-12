class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        // Dummy node
        ListNode* front = new ListNode(0, head);

        // Map: prefixSum -> last node with this prefixSum
        unordered_map<int, ListNode*> prefixSumToNode;

        int prefixSum = 0;

        ListNode* current = front;

        while (current != nullptr) {
            prefixSum += current->val;

            // Keep the LAST occurrence
            prefixSumToNode[prefixSum] = current;

            current = current->next;
        }

        prefixSum = 0;
        current = front;

        while (current != nullptr) {
            prefixSum += current->val;

            // Skip the zero-sum sequence
            current->next = prefixSumToNode[prefixSum]->next;

            current = current->next;
        }

        return front->next;
    }
};