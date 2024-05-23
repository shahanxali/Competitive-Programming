//Question: https://leetcode.com/problems/linked-list-cycle/
//Level: Easy

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::map<ListNode*, int> checkMap;  // Use pointers as keys

        ListNode* current = head;

        bool hasCycle = false;
        while (current != nullptr) {
            // Check if the current node's address is in the map
            if (checkMap.find(current) != checkMap.end()) {
                hasCycle = true;
                break;  // If found, there is a cycle
            }

            // Insert the current node's address into the map
            checkMap[current] = 1;

            // Move to the next node
            current = current->next;
        }

        return hasCycle;
    }
};
