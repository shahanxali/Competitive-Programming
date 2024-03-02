//Question: https://leetcode.com/problems/swap-nodes-in-pairs/
//Level: Medium


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        while (head != nullptr && head->next != nullptr) {
            ListNode* first = head;
            ListNode* second = head->next;


            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            head = first->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
