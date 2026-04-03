class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        map<ListNode*, ListNode*> parent;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        // build parent map
        while(curr){
            parent[curr] = prev;
            prev = curr;
            curr = curr->next;
        }

        ListNode* left = head;
        ListNode* right = prev; // tail

        while(left != right && left->next != right){
            ListNode* nextLeft = left->next;
            ListNode* prevRight = parent[right];

            left->next = right;
            right->next = nextLeft;

            left = nextLeft;
            right = prevRight;
        }

        right->next = NULL;
    }
};