/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>nodes;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            nodes[col][row].insert(node->val);
            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }
            if(node->right){
                q.push({node->right, {row+1, col+1}});
            }

        }
        vector<vector<int>>ans;
        for(auto& column : nodes){
            vector<int>temp;
            for(auto& row : column.second){
                for(int value : row.second){
                    temp.push_back(value);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};