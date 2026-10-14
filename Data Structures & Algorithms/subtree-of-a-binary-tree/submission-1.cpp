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
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        return true;
        if(p==NULL || q==NULL)
        return false;
        if(p->val!=q->val)
        return false;
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
        return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(isSameTree(temp,subRoot))
            return true;
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        return false;
    }
};
