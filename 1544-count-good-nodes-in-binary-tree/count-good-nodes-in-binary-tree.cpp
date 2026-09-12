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
    int solve(TreeNode* root, int maxVal){
        if(root == NULL) return 0;
        int count = 0;
        if(root->val >= maxVal){
            count = 1;
        }
        maxVal = max(maxVal, root->val);
        count += solve(root->left, maxVal);
        count += solve(root->right, maxVal);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};