//Question: https://leetcode.com/problems/invert-binary-tree/description/
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

    void recur(TreeNode* root){

        if(!root){
            return;
        }

        swap(root -> left, root -> right);
        

        recur(root -> left);
        recur(root -> right);

        return;

    }

    TreeNode* invertTree(TreeNode* root) {
        
        recur(root);

        return root;

    }
};