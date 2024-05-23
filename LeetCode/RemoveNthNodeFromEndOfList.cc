//Question: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Level: Medium


//Solution: 1 (beats 66% using iterative sol)(better)



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

    int csize(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp -> next;
            count++;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = csize(head);
        
        int pos = size - n;
        
        if (pos == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        while (count + 1 != pos) {
            count++;
            temp = temp->next;
        }

        if (temp->next->next == NULL) {
            temp->next = NULL;
            return head;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};



//solution: 2 (not better but also a sol)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for (int i = 0; i <= n; ++i) {
            if (fast == nullptr) return nullptr;
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};

