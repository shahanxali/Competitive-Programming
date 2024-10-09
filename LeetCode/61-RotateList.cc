//Question: https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head -> next == NULL || k == 0) return head;

        int size = 1;
        ListNode* temp = head;

        while(temp -> next != NULL){
            size++;
            temp = temp -> next;
        }

        int shift = size - (k % size) - 1;


        temp -> next = head;
        temp = head;

        while(shift--){
            temp = temp -> next;
        }

        head = temp -> next;
        temp -> next = NULL;

        return head;

    }
};
