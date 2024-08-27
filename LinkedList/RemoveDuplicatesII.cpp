class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* temp = NULL;
        while (fast) {
            if (slow->val != fast->val) {
                temp = slow;
                slow = fast;
                fast = fast->next;
            } else {
                while (fast && slow->val == fast->val) {
                    fast = fast->next;
                }
                // If preSlow is null, it means duplicates were found starting from the head
                if (!temp) {
                    head = fast; // Update head to skip the duplicates
                } else {
                    temp->next = fast; // Skip the duplicates 
                }
                slow = fast;
                if (fast)
                    fast = fast->next;
            }
        }
        return head;
    }
};
