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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // slow will reach to the mid
        // now reverse the links from mid in forward dir
        ListNode* temp=slow;
        ListNode* prev=nullptr;
        while(temp!=NULL){
            ListNode* nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        // now reordering listfrom left and right
        ListNode* l=head;
        ListNode* r=prev;
        while( l->next!=r && l!=r){
            ListNode* lnext=l->next;
            ListNode* rnext=r->next;
            l->next=r;
            l=lnext;
            r->next=l;
            r=rnext;
        }
    }
};
