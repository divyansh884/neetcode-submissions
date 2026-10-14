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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        unordered_map<int, int> mp;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int ind = q.front().second;
            q.pop();
            mp[ind] = node->val;
            if (node->left) q.push({node->left, ind+1});
            if (node->right) q.push({node->right, ind+1});
        }
        for (int i = 0; i < mp.size(); i++) {
            res.push_back(mp[i]);
        }
        return res;
    }
};