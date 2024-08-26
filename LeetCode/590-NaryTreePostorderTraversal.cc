//Question: https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
//Level: Easy


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void posttravel(Node* root, vector<int>& ans){

        if(root == NULL){
            return;
        }

        for(int i = 0; i < root -> children.size(); i++){
        
            posttravel(root -> children[i], ans);

        }

        ans.push_back(root -> val);

        return;

    }

    vector<int> postorder(Node* root) {
        
        vector<int> ans;

        posttravel(root, ans);

        return ans;
        
    }
};
