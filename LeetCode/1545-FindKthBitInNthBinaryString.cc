//Question: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2024-10-19
//Level: Medium

class Solution {
public:
    char findKthBit(int n, int k) {

        int count = 1;
        string a = "0";

        while(count < k){

            string temp = a;
            a += "1";

            reverse(temp.begin(), temp.end());

            for(auto c : temp){
                a += c == '1' ? '0' : '1';
            }

            count = a.size();

        }

        return a[k - 1];

    }
};
