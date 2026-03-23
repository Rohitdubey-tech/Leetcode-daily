/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // After this, slow will be at the middle of the linked list
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // In case of odd length, the second half starts at slow->next
        ListNode* second = slow->next;
        slow->next = nullptr;
        
        // Reverse the second half (mid+1 onwards)
        ListNode* curr = second;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Reorder logic
        // Since we have reversed the second half, 
        // the first->next gets connected to second (which is now at prev)
        ListNode* first = head;
        second = prev;
        
        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
};