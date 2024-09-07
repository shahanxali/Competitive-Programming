//Question: https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-07
//Level: Medium

class Solution {
public:

    bool dfs(ListNode* head, ListNode* cur, TreeNode* root) {

        if (cur == NULL) return true;
        if (root == NULL) return false;

        if (cur->val == root->val) {
            cur = cur->next;  // Move to the next list node if value matches
        }
        else if (head->val == root->val) {
            head = head->next; // Start new matching attempt if the value matches head of list
        }
        else {
            cur = head;  // Reset the matching pointer for getting only consecutive matches
        }

        return dfs(head, cur, root->left) || dfs(head, cur, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }

};
