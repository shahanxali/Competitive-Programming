//Question: https://leetcode.com/problems/cousins-in-binary-tree-ii/?envType=daily-question&envId=2024-10-23
//Level: Medium

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

    void BFScreatearr(TreeNode* root, unordered_map<int, int>& store){
        if (!root) return;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            pair<TreeNode*, int> t = q.front();
            q.pop();
            TreeNode* cur = t.first;
            int level = t.second;

            store[level] += cur->val;

            if (cur->left) q.push({cur->left, level + 1});
            if (cur->right) q.push({cur->right, level + 1});
        }
    }

    void BFStreecreation(TreeNode* root, unordered_map<int, int>& store){
        if (!root) return;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            pair<TreeNode*, int> t = q.front();
            q.pop();
            TreeNode* cur = t.first;
            int level = t.second;

            int sum = (cur->left ? cur->left->val : 0) + (cur->right ? cur->right->val : 0);

            if (cur->left) cur->left->val = sum;
            if (cur->right) cur->right->val = sum;

            cur->val = store[level] - cur->val;

            if (cur->left) q.push({cur->left, level + 1});
            if (cur->right) q.push({cur->right, level + 1});
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<int, int> store;

        BFScreatearr(root, store);
        BFStreecreation(root, store);

        return root;
    }
};
