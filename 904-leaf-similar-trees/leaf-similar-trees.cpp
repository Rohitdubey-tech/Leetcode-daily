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
    void getLeaves(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            return;
        } 
        getLeaves(root->left, ans);
        getLeaves(root->right, ans);


    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1, ans2;
        getLeaves(root1, ans1);
        getLeaves(root2, ans2);
        return ans1 == ans2;
    }
};