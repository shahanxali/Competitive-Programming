//Question: https://leetcode.com/problems/same-tree/
//Level: Easy

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
        // If both trees are empty, they are identical
        if (!p && !q) return true;
        // If only one of the trees is empty, they are not identical
        if (!p || !q) return false;

        // Create queues for level-order traversal
        queue<TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);

        // Perform level-order traversal
        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* node1 = queue1.front();
            TreeNode* node2 = queue2.front();
            queue1.pop();
            queue2.pop();

            // If the values of the current nodes are not equal, the trees are not identical
            if (node1->val != node2->val) return false;

            // Enqueue left children
            if (node1->left && node2->left) {
                queue1.push(node1->left);
                queue2.push(node2->left);
            } else if (node1->left || node2->left) {
                return false; // One tree has a left child while the other does not
            }

            // Enqueue right children
            if (node1->right && node2->right) {
                queue1.push(node1->right);
                queue2.push(node2->right);
            } else if (node1->right || node2->right) {
                return false; // One tree has a right child while the other does not
            }
        }

        // If both queues are empty, all nodes are identical
        return queue1.empty() && queue2.empty();
    }
    
};