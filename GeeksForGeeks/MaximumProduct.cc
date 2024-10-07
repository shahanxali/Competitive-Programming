//Question: https://practice.geeksforgeeks.org/contest/gfg-weekly-175-rated-contest-1447/problems
//Level:

class Solution {
  public:
    long long maximumProduct(int n, vector<int> &arr, int l, int r) {
        // Initialize the required variables
        int amax = INT_MIN, amin = INT_MAX; // max and min outside range
        int bmax = INT_MIN, bmin = INT_MAX; // max and min inside range

        l--; // Convert to 0-based index
        r--; // Convert to 0-based index

        // Loop through the array to find max and min inside and outside the range
        for(int i = 0; i < arr.size(); i++) {
            if(i >= l && i <= r) {
                // Inside the range [l, r]
                bmax = max(bmax, arr[i]);
                bmin = min(bmin, arr[i]);
            } else {
                // Outside the range [l, r]
                amax = max(amax, arr[i]);
                amin = min(amin, arr[i]);
            }
        }

        // Now, compute the maximum product considering all possible combinations
        long long product1 = (long long)amax * bmax; // Max outside * Max inside
        long long product2 = (long long)amax * bmin; // Max outside * Min inside
        long long product3 = (long long)amin * bmax; // Min outside * Max inside
        long long product4 = (long long)amin * bmin; // Min outside * Min inside

        // Return the maximum of these products
        return max({product1, product2, product3, product4});
    }
};
