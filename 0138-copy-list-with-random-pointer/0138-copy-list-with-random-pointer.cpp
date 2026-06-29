/*
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        // Step 1: Insert copied nodes
        Node* temp = head;

        while(temp != NULL){
            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }

        // Step 2: Copy random pointers
        temp = head;

        while(temp != NULL){

            if(temp->random != NULL)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // Step 3: Separate the lists
        Node* dummy = new Node(0);
        Node* copy = dummy;

        temp = head;

        while(temp != NULL){

            copy->next = temp->next;
            copy = copy->next;

            temp->next = temp->next->next;
            temp = temp->next;

            if(copy->next != NULL)
                copy->next = copy->next->next;
        }

        return dummy->next;
    }
};