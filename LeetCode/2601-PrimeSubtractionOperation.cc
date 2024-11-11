//Question: https://leetcode.com/problems/prime-subtraction-operation/description/?envType=daily-question&envId=2024-11-11
//Level: Medium

class Solution {
public:

    bool isprime(int num){

        if(num == 0 || num == 1) return false;

        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;

    }

    int change(int small, int val){

        int temp = small + 1;
        if(temp > val) return -1;
        while(temp < val){
            if(isprime(val - temp)) return temp;
            temp++;
        }

        return val;

    }

    bool primeSubOperation(vector<int>& nums) {

        nums[0] = change(0, nums[0]);
        cout << nums[0] << " ";

        for(int i = 1; i < nums.size(); i++){
            nums[i] = change(nums[i - 1], nums[i]);
            cout << nums[i] << " ";
            if(nums[i] == -1) return false;
        }
        return true;

    }
};
