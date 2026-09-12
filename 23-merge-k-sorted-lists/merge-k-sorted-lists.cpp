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
    struct compare{
        bool operator()
            (ListNode* a, ListNode* b){
                return a->val > b->val;
            }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(auto head : lists){
            if(head != NULL){
            pq.push(head);
            }
        }
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;
            while(!pq.empty()){
                ListNode* node = pq.top();
                pq.pop();
                curr->next = node;
                curr = curr->next;
                if(node->next != NULL){
                    pq.push(node->next);
                }
            }
        return dummy->next;
    }
};