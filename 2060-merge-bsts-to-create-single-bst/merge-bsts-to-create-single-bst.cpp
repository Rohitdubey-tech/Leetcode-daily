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

    void leaf(TreeNode* node, unordered_set<int> &st){
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL){
            st.insert(node->val);
            return;
        }
        leaf(node->left, st);
        leaf(node->right, st);
    }

      void merge(TreeNode* node, unordered_map<int, TreeNode*>& mp)
    {
        if(node == NULL)    return; 
        if(node->left == NULL && node->right == NULL && mp.count(node->val))    
        {
            TreeNode* sub = mp[node->val];
            node->left = sub->left;
            node->right = sub->right;
            mp.erase(node->val);
        } 
        merge(node->left, mp);
        merge(node->right, mp);
    }
  
     bool isbst(TreeNode* node, long low, long high)
    {
        if(node == NULL)    return true; 
        if(node->val <= low || node->val >= high)   return false;

        return isbst(node->left, low, node->val) && isbst(node->right, node->val, high);
    }
    TreeNode* canMerge(vector<TreeNode*> & trees){
        if(trees.size() == 1) return trees[0];
        unordered_set<int> leaves;
        unordered_map<int, TreeNode*> mp;
        for(auto t: trees){
            mp[t->val] = t;
            leaf(t, leaves);
        }
        TreeNode* root = NULL;
        for(auto t: trees){
            if( !leaves.count ( t->val)){
                if(root) return NULL;
                root = t;
            }
        }
        if( !root) return NULL;
              mp.erase(root->val);

        merge(root, mp);
        if(!mp.empty()) return NULL;
        if(!isbst(root, LONG_MIN, LONG_MAX))    return NULL;
        return root;

    }
};

