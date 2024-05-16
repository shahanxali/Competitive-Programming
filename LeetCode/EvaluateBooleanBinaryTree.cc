//Question: https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?envType=daily-question&envId=2024-05-16
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

    int recur(TreeNode* root){

        if(root -> left == NULL && root -> right == NULL){
            return root -> val;
        }

        int left = recur(root -> left);
        int right = recur(root -> right);

        return (root -> val == 2) ? ((left) || (right)) : ((left) && (right));

    }

    bool evaluateTree(TreeNode* root) {


        return recur(root);


    }
};