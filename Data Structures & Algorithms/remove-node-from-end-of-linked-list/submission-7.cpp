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
        if(head==NULL)return head;
        int s=0;
        ListNode* temp=head;
        while(temp!=NULL){
            s++;
            temp=temp->next;
        }
        if(s==n){
            return head->next;
        }
        int todelete=s-n-1;
        temp=head;
        while(todelete--){
            temp=temp->next;
        }

        temp->next=temp->next->next;
        // temp->next->next=NULL;
        return head;
        
    }
};
