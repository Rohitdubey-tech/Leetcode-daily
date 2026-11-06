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
    int ans = 0;
    void solve(TreeNode* root, int left, int right){
        if(root == NULL) return ;
        ans = max(ans, max(left, right));
        solve(root->left, right+1, 0);
        solve(root->right, 0, left+1);

    }
    int longestZigZag(TreeNode* root) {
        solve(root, 0,0);
        return ans;
    }
};