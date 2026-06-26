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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp=head;
        ListNode* last=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        int nth=count-n;
        if(nth==0) head=head->next;
        
        int countn=0;
        ListNode* prev=NULL;
        while(countn!=nth){
            prev=last;
            if(last!=NULL) last=last->next;
            countn++;
            
        }
        if(prev!=NULL) prev->next=prev->next->next;
        
        
        
        return head;
    }
};