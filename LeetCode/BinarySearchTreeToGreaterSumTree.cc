//Question: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/?envType=daily-question&envId=2024-06-25
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

    int count = 0;

    void recur(TreeNode* root){

        if(root == NULL){
            return;
        }

        recur(root -> right);
        count += (root -> val);
        root -> val = count;
        recur(root -> left);

        return;

    }

    TreeNode* bstToGst(TreeNode* root) {
        
        recur(root);

        return root;

    }
};
