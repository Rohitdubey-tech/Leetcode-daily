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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);
        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                tail->next = left;
                left=left->next;
                tail = tail->next;

            }
            else{
                tail->next = right;
                right = right->next;
                tail = tail->next;
            }
     }
     if(left != NULL){
        tail->next = left;
     }
     else{
        tail->next = right;
     }
     return dummy.next;

    }
};