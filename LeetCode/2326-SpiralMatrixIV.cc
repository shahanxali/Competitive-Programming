//Question:
//Level: Medium

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> ans(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (head) {


            // Fill top row
            for (int col = left; col <= right && head; col++) {
                ans[top][col] = head->val;
                head = head->next;
            }
            top++;


            // Fill right column
            for (int row = top; row <= bottom && head; row++) {
                ans[row][right] = head->val;
                head = head->next;
            }
            right--;


            // Fill bottom row
            for (int col = right; col >= left && head; col--) {
                ans[bottom][col] = head->val;
                head = head->next;
            }
            bottom--;


            // Fill left column
            for (int row = bottom; row >= top && head; row--) {
                ans[row][left] = head->val;
                head = head->next;
            }
            left++;


        }

        return ans;
    }
};
