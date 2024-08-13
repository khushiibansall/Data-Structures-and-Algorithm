//linked list is sorted
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr; // Handle empty list case
        if (head->next == nullptr) {
            return head;
        }
        ListNode* p = head; // Initialize pointer

        while (p != nullptr &&
               p->next != nullptr) {      // Traverse until the end of the list
            if (p->val == p->next->val) { // Check for duplicate
                p->next = p->next->next;  // Remove duplicate
            } else {
                p = p->next; // Move to next node
            }
        }

        return head;

        
    }
};
