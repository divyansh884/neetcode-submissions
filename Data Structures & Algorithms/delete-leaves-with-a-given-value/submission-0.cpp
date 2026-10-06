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
void f(TreeNode* &root,int target){
    if(root==nullptr)
        return;
    f(root->left,target);
    f(root->right,target);
    if(root->val==target && root->left==NULL && root->right==NULL)
        root=NULL;
}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        f(root,target);
        return root;
    }
};