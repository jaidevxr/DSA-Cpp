/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k--;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {

            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverse(temp);

            if (temp == head)
                head = kthNode;
            else
                prevLast->next = kthNode;

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};