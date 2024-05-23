//Question: https://leetcode.com/problems/reorder-list/
//Level: Medium



//Aproach: 1 (Iterative, not good)

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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* temp1 = head;
        while (temp1 != NULL) {
            ListNode* temp2 = temp1;
            while (temp2->next != NULL && temp2->next->next != NULL) {
                temp2 = temp2->next;
            }
            if (temp1 == temp2) {
                break; 
            }
            ListNode* last = temp2->next;
            temp2->next = NULL; 
            last->next = temp1->next; 
            temp1->next = last;
            temp1 = last->next;
        }
    }
};




