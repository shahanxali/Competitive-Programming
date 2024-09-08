//Question: https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08
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

    int findsize(ListNode* head){

        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;

    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int llength = findsize(head);

        int parts = llength / k;
        int remains = llength % k;

        vector<ListNode*> ans;

        ListNode* temp = head;

        while(k--){

            int count = parts;
            if(remains != 0){
                count++;
                remains--;
            };

            ListNode* temphead = temp;
            ListNode* prev = NULL;
            while(count-- && temp != NULL){
                prev = temp;
                temp = temp -> next;
            }

            if(prev != NULL)
                prev -> next = NULL;

            ans.push_back(temphead);


        }

        return ans;


    }
};
