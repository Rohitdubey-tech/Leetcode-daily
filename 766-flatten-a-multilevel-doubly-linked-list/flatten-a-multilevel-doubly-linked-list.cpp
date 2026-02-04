/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
	for (Node* curr = head; curr; curr = curr->next)
	{
		if (curr->child)
		{
			Node* next = curr->next;
			curr->next = curr->child;
			curr->next->prev = curr;
			curr->child = NULL;
			Node* p = curr->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;

    }
};