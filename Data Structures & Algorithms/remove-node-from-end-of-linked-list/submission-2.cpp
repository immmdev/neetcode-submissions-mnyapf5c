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
    if(head==NULL || head->next==NULL)return nullptr;
        int k=0;

        // finding length of list
        ListNode* t=head;
        while(t!=nullptr){
            t=t->next;
            k++;
        } 

        // handling when required to remove head
        if(k==n){
            ListNode* oh=head;
            head=head->next;
            oh->next=nullptr;
        return head;
        } 

        // finding element just before target
        int target=k-n-1;
        t=head;
        while(target!=0){
            t=t->next;
            target--;
        }

        ListNode* toDelete=t->next;
        t->next=toDelete->next;
        toDelete->next=nullptr;
        return head;
    }
};
