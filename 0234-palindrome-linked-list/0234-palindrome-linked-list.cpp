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
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL;
        ListNode *curr = slow;

        while(curr != NULL){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *first = head;
        ListNode *second = prev;

        while(second != NULL){
            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};