//Question: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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

    void BFS(TreeNode* root, int& ans){

        queue<TreeNode*> q;
        q.push(root);
        int maxi = root -> val, level = 1, temp = root -> val;

        while(!q.empty()){

            int size = q.size();

            if(temp > maxi){
                maxi = temp;
                ans = level;
            }

            temp = 0;

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();

                if(node -> left != nullptr){
                    q.push(node -> left);
                    temp += node -> left -> val;
                }
                if(node -> right != nullptr){
                    q.push(node -> right);
                    temp += node -> right -> val;
                }

            }

            level++;


        }

        return;

    }

    int maxLevelSum(TreeNode* root) {

        int ans = 1;

        BFS(root, ans);

        return ans;

    }
};
