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
    vector<vector<int>>result;
    vector<int>path;
    void dfs(TreeNode* root, int targetSum){
        if(root == nullptr) return;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            if(targetSum == root->val){
                result.push_back(path);
            }
            path.pop_back();
            return;
        }
        targetSum -= root->val;
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return result;
    }
};