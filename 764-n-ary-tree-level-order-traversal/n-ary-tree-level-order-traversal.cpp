/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        if(root == NULL) return ans;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
               for(Node* child : node->children){
                if(child)
                q.push(child);
               }
            }
            ans.push_back(level);
        }
        return ans;
    }
};