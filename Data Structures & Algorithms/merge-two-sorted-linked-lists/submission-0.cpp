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
// intution: take a dummmy then traverse the array by taking two points ans a tail pointer keep adding small element at each comparision
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        // DUMMY NODE & TEMP ARE POINTING TO THE SAME ADDRESS
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                // join the tail to the next req node
                temp->next=temp1;
                // moving traversal pointer
                temp=temp1;
                // move to that location
                temp1=temp1->next;   
            } else {
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        // if left nodes in any list then join the tail to that
        if(temp1) temp->next=temp1;
        if(temp2) temp->next=temp2;
        // as dummy was not moved its next pointing to head
        return dummyNode->next;
    }
};