class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        unordered_set<int> mpp;
        ListNode* temp = head;

        mpp.insert(temp->val);

        while (temp->next) {
            if (mpp.find(temp->next->val) != mpp.end()) {
                temp->next = temp->next->next;
            } else {
                mpp.insert(temp->next->val);
                temp = temp->next;
            }
        }

        return head;
    }
};