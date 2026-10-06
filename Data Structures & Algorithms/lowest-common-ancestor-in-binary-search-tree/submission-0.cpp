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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        return NULL;
        if(root->val>=min(p->val,q->val) && root->val<=max(p->val,q->val))
        return root;
        if(root->val>max(p->val,q->val)){
        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        if(left)
        return left;
        }
        if(root->val<min(p->val,q->val)){
        TreeNode* right= lowestCommonAncestor(root->right,p,q);
        if(right)
        return right;
        }
    }
};
