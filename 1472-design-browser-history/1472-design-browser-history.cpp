class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string s) {
        url = s;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {

        Node* newNode = new Node(url);

        curr->next = newNode;
        newNode->prev = curr;

        curr = newNode;
    }

    string back(int steps) {

        while(curr->prev != NULL && steps--) {
            curr = curr->prev;
        }

        return curr->url;
    }

    string forward(int steps) {

        while(curr->next != NULL && steps--) {
            curr = curr->next;
        }

        return curr->url;
    }
};