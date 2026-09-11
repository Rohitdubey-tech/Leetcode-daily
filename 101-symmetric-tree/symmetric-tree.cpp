class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        queue<pair<TreeNode*, TreeNode*>> q;

        q.push({root->left, root->right});

        while(!q.empty()) {

            auto front = q.front();
            q.pop();

            TreeNode* a = front.first;
            TreeNode* b = front.second;

            if(a == NULL && b == NULL)
                continue;

            if(a == NULL || b == NULL)
                return false;

            if(a->val != b->val)
                return false;

            q.push({a->left, b->right});
            q.push({a->right, b->left});
        }

        return true;
    }
};