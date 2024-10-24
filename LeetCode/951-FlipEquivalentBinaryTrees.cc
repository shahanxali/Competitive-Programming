//Question: https://leetcode.com/problems/flip-equivalent-binary-trees/?envType=daily-question&envId=2024-10-24
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

    bool fliprec(TreeNode* root1, TreeNode* root2){

        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;

        return fliprec(root1 -> left, root2 -> left) && fliprec(root1 -> right, root2 -> right)
        || fliprec(root1 -> left, root2 -> right) && fliprec(root1 -> right, root2 -> left);

    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        return fliprec(root1, root2);

    }
};
