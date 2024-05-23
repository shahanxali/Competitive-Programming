//Question: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
//Level: Hard

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

    int ans = INT_MIN;

    int recur(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int leftl = max(0, recur(root -> left));
        int rightl = max(0, recur(root -> right));

        int a = max(leftl + root -> val, rightl + root -> val);
        ans = max(ans, max(a, leftl + rightl + root -> val));

        return a;

    }

    int maxPathSum(TreeNode* root) {
        
        recur(root);
        return ans;

    }
};