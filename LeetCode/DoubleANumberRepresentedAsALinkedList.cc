//Question: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07
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

    int car = 0;
    
    void recur(ListNode* head) {
        if (head == NULL) 
            return;
        
        recur(head -> next);
        
        int cur = 2 * head -> val + car;
        car = cur / 10;
        
        head -> val = cur % 10;
    }

    ListNode* doubleIt(ListNode* head) {
        
        car = 0;
        recur(head);

        if(car){
            ListNode* a = new ListNode();
            a -> val = car;
            a -> next = head;
            head = a; 
        }

        return head;
    }
};
