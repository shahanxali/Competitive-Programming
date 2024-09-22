//Qestion: https://practice.geeksforgeeks.org/contest/job-a-thon-37-hiring-challenge/problems
//Level:

class Solution {
  public:

  // Helper function to compute GCD
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Function to compute LCM using GCD
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b; // Using the relationship lcm(a, b) = (a * b) / gcd(a, b)
    }

    int minMod(int n, int arr[]) {
        // code here

        // Check if 1 is present in the array
        bool hasOne = false;

        for(int i = 0; i < n; i++) {
            if(arr[i] == 1) {
                hasOne = true;
                break;
            }
        }

        // If 1 is not present, return 1
        if(!hasOne) {
            return 1;
        }

        // Calculate LCM of the array
        int lcmValue = arr[0];
        for(int i = 1; i < n; i++) {
            lcmValue = lcm(lcmValue, arr[i]);
        }

        return lcmValue;


    }

};
