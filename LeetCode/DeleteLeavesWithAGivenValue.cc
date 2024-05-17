//Question: https://leetcode.com/problems/delete-leaves-with-a-given-value/description/?envType=daily-question&envId=2024-05-17
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

    TreeNode* recur(TreeNode* root, int target){

        if (root == NULL) {
            return NULL;
        }

        root -> left = recur(root->left, target);
        root -> right = recur(root->right, target);

        if(root -> val == target && root -> left == NULL && root -> right == NULL){
            return NULL;
        }

        if (root -> left == NULL && root -> right == NULL && root -> val == target) {
            delete root;
            return NULL;
        }

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        return recur(root, target);

    }
};