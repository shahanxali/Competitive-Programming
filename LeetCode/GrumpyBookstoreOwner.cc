//Question: https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
//Level: Medium



class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();
        int totalSatisfied = 0;

        // Calculate the satisfied customers when the owner is not grumpy
        for (int i = 0; i < n; ++i) {

            if (grumpy[i] == 0) {
                totalSatisfied += customers[i];
            }

        }

        // Initial window sum of grumpy customers for the first 'minutes' interval
        int maxi = 0;
        int current = 0;
        
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                current += customers[i];
            }
        }

        maxi = current;

        // Slide the window across the array
        for (int i = minutes; i < n; ++i) {

            if (grumpy[i] == 1) {
                current += customers[i];
            }

            if (grumpy[i - minutes] == 1) {
                current -= customers[i - minutes];
            }

            maxi = max(maxi, current);

        }

        // Total satisfied customers is the sum of initially satisfied plus the max additional satisfied
        return totalSatisfied + maxi;


    }
};
