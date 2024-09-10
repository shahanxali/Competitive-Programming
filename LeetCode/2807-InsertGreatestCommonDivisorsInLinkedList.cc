//Question: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10
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

    // int gcd(int a, int b){

    //     if(a % b == 0){
    //         return b;
    //     }

    //     return gcd(b, a % b);

    // }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        if(!(head -> next)){
            return head;
        }

        ListNode* first = head;
        ListNode* second = first -> next;

        while(second){

            //We used __gcd() from <algorithm> instead of using function
            //but it is same as implemented above, I used here for space complexity

            ListNode* temp = new ListNode(__gcd(first -> val, second -> val));
            first -> next = temp;
            temp -> next = second;
            first = second;
            second = second -> next;

        }

        return head;

    }
};
