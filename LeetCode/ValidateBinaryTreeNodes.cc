//Question: https://leetcode.com/problems/validate-binary-tree-nodes/description/
//Level: Medium


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // Create a vector to track the parent of each node.
        vector<int> parent(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                // If the left child already has a parent, return false.
                if (parent[leftChild[i]] != -1) {
                    return false;
                }
                parent[leftChild[i]] = i;
            }
            if (rightChild[i] != -1) {
                // If the right child already has a parent, return false.
                if (parent[rightChild[i]] != -1) {
                    return false;
                }
                parent[rightChild[i]] = i;
            }
        }
        
        int rootCount = 0;
        int root = -1;
        
        // Find the root node (a valid binary tree has one root).
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                rootCount++;
                root = i;
            }
        }
        
        // If there is no root or more than one root, return false.
        if (rootCount != 1) {
            return false;
        }
        
        // Perform a DFS to check if it's a valid binary tree.
        vector<bool> visited(n, false);
        stack<int> stack;
        stack.push(root);
        
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            visited[node] = true;
            
            if (leftChild[node] != -1) {
                if (visited[leftChild[node]]) {
                    return false; // Detected a cycle.
                }
                stack.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                if (visited[rightChild[node]]) {
                    return false; // Detected a cycle.
                }
                stack.push(rightChild[node]);
            }
        }
        
        // Check if all nodes are visited, indicating a connected tree.
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        
        return true;
    }
};
