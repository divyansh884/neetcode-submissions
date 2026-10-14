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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            TreeNode* par = q.front().second;
            q.pop();
            if (temp->val == key) {
                if (temp->right == nullptr) {
                    if (par == NULL) {
                        root = temp->left;
                        break;
                    }
                    if (par->left == temp)
                        par->left =temp->left;
                    else
                        par->right = temp->left;
                    break;
                } else {
                    TreeNode* exe = temp;
                    TreeNode* curr = temp->right;
                    TreeNode* par = temp;
                    while (curr->left) {
                        par = curr;
                        curr = curr->left;
                    }
                    swap(curr->val, exe->val);
                    if (par->left == curr) {
                        par->left = curr->right;
                    } else
                        par->right = curr->right;
                    break;
                }

            } else {
                if (temp->val < key && temp->right) {
                    q.push({temp->right, temp});
                } else if (temp->val > key && temp->left) {
                    q.push({temp->left, temp});
                }
            }
        }
        return root;
    }
};