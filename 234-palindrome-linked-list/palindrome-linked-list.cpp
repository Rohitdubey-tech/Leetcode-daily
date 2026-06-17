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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        ListNode* secondHalf = reverse(slow);
        ListNode* firstHalf = head;
        while(secondHalf){
        if(firstHalf->val != secondHalf->val){
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf= secondHalf->next;
        }
        return true;
    }
};