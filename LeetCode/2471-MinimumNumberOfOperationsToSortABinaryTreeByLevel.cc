//Question: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/?envType=daily-question&envId=2024-12-23
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

    int minswap(vector<int> vec) {
        int ans = 0;
        vector<bool> visited(vec.size(), false);
        vector<int> temp = vec;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> store;

        for (int i = 0; i < temp.size(); i++){
            store[temp[i]] = i;
        }

        for (int i = 0; i < vec.size(); i++){

            if (!visited[i] && store[vec[i]] != i){
                int j = i, count = 0;

                while (!visited[j]){
                    count++;
                    visited[j] = true;
                    j = store[vec[j]];

                }

                ans += count - 1;
            }

        }

        return ans;

    }


    int bfs(TreeNode* root){

        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while(!q.empty()){
            int size = q.size();

            vector<int> vec;
            for(int i = 0; i < size; i++){
                TreeNode* t = q.front();
                q.pop();

                vec.push_back(t -> val);

                if(t -> left != nullptr) q.push(t -> left);
                if(t -> right != nullptr) q.push(t -> right);
            }

            ans += minswap(vec);

        }

        return ans;

    }

    int minimumOperations(TreeNode* root) {

        return bfs(root);

    }
};
