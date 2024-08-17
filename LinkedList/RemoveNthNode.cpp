class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Calculate the total length of the list
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        // Step 2: Determine the position of the node to be removed
        int target = length - n;

        // Step 3: If the head needs to be removed
        if (target == 0) {
            ListNode* newHead = head->next;
            delete head; // Free the memory of the old head
            return newHead;
        }

        // Step 4: Traverse to the node just before the target node
        curr = head;
        for (int i = 0; i < target - 1; i++) {
            curr = curr->next;
        }

        // Step 5: Remove the target node
        ListNode* toRemove = curr->next;
        curr->next = curr->next->next;
        delete toRemove; // Free the memory of the removed node

        return head;
    }
};
