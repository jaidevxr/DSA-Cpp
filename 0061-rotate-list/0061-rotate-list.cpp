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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and last node
        int len = 1;
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        k = k % len;

        if(k == 0)
            return head;

        // Make circular list
        tail->next = head;

        // Find new last node
        int steps = len - k - 1;
        ListNode* newTail = head;

        while(steps--){
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break circle
        newTail->next = NULL;

        return newHead;
    }
};