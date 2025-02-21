//Question: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21
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
class FindElements {
public:

    TreeNode* graph = new TreeNode();

    FindElements(TreeNode* root) {
        graph = root;
    }

    bool find(int target) {

        vector<char> temp;

        while(target > 0){
            if(target % 2 == 0){
                target -= 2;
                temp.push_back('r');
            }
            else{
                target -= 1;
                temp.push_back('l');
            }
            target /= 2;

        }

        TreeNode* check = graph;
        for(int i = temp.size() - 1; i >= 0; i--){

            check = temp[i] == 'l' ? check -> left : check -> right;

            if(check == nullptr) return false;
        }

        return true;

    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
