//Question: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
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

    void BFS(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents, vector<TreeNode*>& deepest){

        queue<TreeNode*> q;
        q.push(root);
        parents[root] = nullptr;

        deepest.push_back(root);

        while(!q.empty()){

            int size = q.size();
            deepest.clear();
            for(int i = 0; i < size; i++){

                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left != nullptr){
                    q.push(temp -> left);
                    parents[temp -> left] = temp;

                }
                if(temp -> right != nullptr){
                    q.push(temp -> right);
                    parents[temp -> right] = temp;
                }
                if(temp -> left == nullptr && temp -> right == nullptr){
                    deepest.push_back(temp);
                }

            }

        }

        return;

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        unordered_map<TreeNode*, TreeNode*> parents;
        vector<TreeNode*> deepest;
        BFS(root, parents, deepest);

        if(deepest.size() == 1) return deepest[0];

        TreeNode* ans = nullptr;

        while(ans == nullptr){

            bool check = false;
            for(int i = 0; i < deepest.size(); i++){
                deepest[i] = parents[deepest[i]];
            }
            for(int i = 0; i < deepest.size() - 1; i++){
                if(deepest[i] == deepest[i + 1]){
                    check = true;
                }
                else{
                    check = false;
                    break;
                }
            }
            if(check){
                ans = deepest[0];
            }

        }

        return ans;

    }
};
