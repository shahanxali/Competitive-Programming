//QUestion: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/?envType=daily-question&envId=2024-07-18
//Level: Medium

class Solution {
public:
    void findLeafs(TreeNode* root, vector<vector<TreeNode*>> &store, vector<TreeNode*> &temp) {
        if (root == NULL) {
            return;
        }

        temp.push_back(root);

        if (root->left == NULL && root->right == NULL) {
            store.push_back(temp);
        }

        findLeafs(root->left, store, temp);
        findLeafs(root->right, store, temp);

        temp.pop_back(); // Backtrack
    }

    int countPairs(TreeNode* root, int distance) {
        vector<vector<TreeNode*>> store;
        vector<TreeNode*> temp;

        findLeafs(root, store, temp);

        int ans = 0;

        for (int i = 0; i < store.size(); i++) {
            for (int j = i + 1; j < store.size(); j++) {
                int l = 0;

                while ((store[i][l] == store[j][l])) {
                    l++;
                }

                if ((store[i].size() - l + store[j].size() - l) <= distance) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

