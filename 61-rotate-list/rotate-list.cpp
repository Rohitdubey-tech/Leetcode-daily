class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode* tail = head;
        int length = 1;
        while(tail->next){
            tail = tail->next;
            length++;
        }
        k = k % length;
        if(k == 0)
            return head;
        tail->next = head;
        int steps = length - k;
        ListNode* newTail = head;
        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};