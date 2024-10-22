//Question:
//Level: Medium


//Using DFS (NOT GOOD)


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

    void DFS(TreeNode* root, unordered_map<int, long long>& store, int level){

        if(!root){
            return;
        }

        level += 1;

        store[level] += root -> val;

        DFS(root -> left, store, level);
        DFS(root -> right, store, level);

        level -= 1;

        return;

    }

    long long kthLargestLevelSum(TreeNode* root, int k) {

        unordered_map<int, long long> store;
        DFS(root, store, 0);

        if(store.size() < k) return -1;

        vector<pair<int, long long>> vec(store.begin(), store.end());

        sort(vec.begin(), vec.end(), [](pair<int, long long> a, pair<int, long long> b){
            return a.second > b.second;
        });

        return vec[k - 1].second;

    }
};



//Using BFS


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

    void BFS(TreeNode* root, unordered_map<int, long long>& store){

        queue<pair<TreeNode*, int>> q;
        int level = 1;

        q.push({root, level});

        while(!q.empty()){

            pair<TreeNode*, int> temp = q.front();
            q.pop();

            store[temp.second] += temp.first -> val;

            if((temp.first -> left)) q.push({temp.first -> left, temp.second + 1});
            if((temp.first -> right)) q.push({temp.first -> right, temp.second + 1});

        }

        return;

    }

    long long kthLargestLevelSum(TreeNode* root, int k) {

        unordered_map<int, long long> store;

        BFS(root, store);

        if(store.size() < k) return -1;

        vector<pair<int, long long>> vec(store.begin(), store.end());

        sort(vec.begin(), vec.end(), [](pair<int, long long> a, pair<int, long> b){
            return a.second > b.second;
        });

        return vec[k - 1].second;

    }
};
