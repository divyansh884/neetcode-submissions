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
void f(TreeNode* root,int maxi,int &cnt){
    if(root==NULL)
    return;
    if(maxi<=root->val){
    cnt++;
    }
    f(root->left,max(maxi,root->val),cnt);
    f(root->right,max(maxi,root->val),cnt);
}
    int goodNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        int cnt=0;
        int maxi=root->val;
        f(root,maxi,cnt);
        return cnt;
    }
};
