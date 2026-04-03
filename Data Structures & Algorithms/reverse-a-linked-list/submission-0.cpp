/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* temp=head;
        ListNode* prevNode=nullptr;
        while(temp!=nullptr){
            ListNode* nextNode=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=nextNode;
        }

        return prevNode;
    }
};
