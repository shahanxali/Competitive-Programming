//Question: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
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

    TreeNode* constructTree(int curNodeVal, map<int, pair<int, int>>& childrenHashmap) {
        TreeNode* newNode = new TreeNode(curNodeVal);
        if (childrenHashmap.find(curNodeVal) != childrenHashmap.end()) {
            auto& children = childrenHashmap[curNodeVal];
            if (children.first != -1) {
                newNode->left = constructTree(children.first, childrenHashmap);
            }
            if (children.second != -1) {
                newNode->right = constructTree(children.second, childrenHashmap);
            }
        }
        return newNode;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> childrenSet;
        map<int, pair<int, int>> childrenHashmap;

        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2] == 1;

            if (childrenHashmap.find(parent) == childrenHashmap.end()) {
                childrenHashmap[parent] = { -1, -1 };
            }

            childrenSet.insert(child);
            if (isLeft) {
                childrenHashmap[parent].first = child;
            } else {
                childrenHashmap[parent].second = child;
            }
        }

        int headNodeVal;
        for (auto& [parent, children] : childrenHashmap) {
            if (childrenSet.find(parent) == childrenSet.end()) {
                headNodeVal = parent;
                break;
            }
        }

        return constructTree(headNodeVal, childrenHashmap);
    }

};
