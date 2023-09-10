//Question: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
//Level: Medium

class Solution {
public:
       int count=0;

       int pre(TreeNode* root, int k) {
            if (root == nullptr) {
                return -1; // Indicates that we didn't find the kth element in this branch.
            }
        
            int left = pre(root->left, k);
        
            if (left != -1) {
                return left; // We found the kth element in the left subtree.
            }
        
            count++;
            if (count == k) {
                return root->val; // This is the kth smallest element.
            }
        
            return pre(root->right, k); // Check the right subtree.
        }

    int kthSmallest(TreeNode* root, int k) {
        return pre(root,k);
    }
};