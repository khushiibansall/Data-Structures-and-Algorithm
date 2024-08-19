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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next; // Save the next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev to current node
            curr = next;       // Move to the next node
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = head;
        ListNode* rev = reverseList(slow);
        while(rev->next !=nullptr){
            ListNode* tempcurr = curr->next;
            curr->next= rev;

            ListNode* temprev = rev->next;
            rev->next= tempcurr;

            curr=tempcurr;
            rev= temprev;

        }
    }
};
