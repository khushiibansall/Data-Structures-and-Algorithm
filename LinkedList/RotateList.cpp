class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* p= head;
        int n=0;
        while(p){
            p=p->next;
            n++;
        }
        k = k % n;
        if (k == 0) return head;
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* next= NULL;
        ListNode* temp= head;
        int count =0;
        while(count < n - k){
            next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        ListNode* prev1=NULL;
        while(curr){
            next= curr->next;
            curr->next=prev1;
            prev1=curr;
            curr=next;
        }
        temp->next=prev1;
        curr=prev;
        prev=NULL;
        next=NULL;
        while(curr){
            next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
