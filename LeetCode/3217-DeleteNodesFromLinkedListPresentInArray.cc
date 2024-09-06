//Question: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06
//Level; Medium


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_map<int, bool> store;

        for(int i = 0; i < nums.size(); i++){
            store[nums[i]] = true;
        }

        // if(head -> next == NULL){
        //     if(store.find(head -> val) != store.end()){
        //         return NULL;
        //     }
        //     else{
        //         return head;
        //     }
        // }


        while(store.find(head -> val) != store.end()){
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }

        ListNode* second = head -> next;
        ListNode* first = head;

        while(second != NULL){
            if(store.find(second -> val) != store.end()){
                ListNode* temp = second;
                second = second -> next;
                first -> next = second;
                delete temp;
            }
            else{
                first = second;
                second = second -> next;
            }
        }

        return head;

    }
};
