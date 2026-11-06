class Solution {
public:
    int countPath(TreeNode* root, long long target) {
        if(root == NULL) return 0;
        int count = 0;
        if(root->val == target) count++;
        count += countPath(root->left, target - root->val);
        count += countPath(root->right, target - root->val);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int count = countPath(root, targetSum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
};