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
    TreeNode* build(vector<int>& preorder, vector<int>&postorder, int preStart, int preEnd, int postStart, int postEnd){
        if(preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) return root;
        int leftRoot = preorder[preStart+1];
        int index = postStart;
        while(postorder[index] != leftRoot){
            index++;
        }
        int leftSize = index - postStart + 1;
        root->left = build(preorder, postorder, preStart+1, preStart+leftSize, postStart, index);
        root->right=build(preorder, postorder, preStart+leftSize+1,preEnd, index+1, postEnd-1);
        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, postorder, 0, preorder.size()-1, 0,postorder.size()-1);
    }
};