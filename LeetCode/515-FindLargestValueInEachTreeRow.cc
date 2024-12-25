//Question: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25
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

    vector<int> bfs(TreeNode* root){

        if(root == nullptr) return {};

        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            int maxi = INT_MIN;
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                maxi = max(maxi, temp -> val);
                q.pop();

                if(temp -> left != nullptr) q.push(temp -> left);
                if(temp -> right != nullptr) q.push(temp -> right);

            }

            ans.push_back(maxi);
        }

        return ans;


    }

    vector<int> largestValues(TreeNode* root) {

        return bfs(root);

    }
};
