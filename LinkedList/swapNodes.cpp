class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int length=0;
        ListNode* p=head;
        while(p){
            p=p->next;
            length++;
        }
        if (k > length) {
            return head; // No swap can be performed if k is invalid
        }
        p=head;
        int begin=1;
        while(begin<k && p->next){
            p=p->next;
            begin++;
        }
        int temp1=p->val;
        int kNew=length-k; //5-2=3
        int end=1;
        ListNode* q=head;
        while(end<=kNew){
            q=q->next;
            end++;
        }
        p->val=q->val;
        q->val=temp1;
        return head;
    }
};
