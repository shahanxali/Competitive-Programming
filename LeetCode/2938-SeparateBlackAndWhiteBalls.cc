//Question: https://leetcode.com/problems/separate-black-and-white-balls/?envType=daily-question&envId=2024-10-15
//Level: Medium

class Solution {
public:
    long long minimumSteps(string s) {

        vector<int> stack1, stack2;
        int startpoint = 0, endpoint = s.size() - 1;

        while(startpoint < s.size() && s[startpoint] == '0'){
            startpoint++;
        }
        while(endpoint >= 0 && s[endpoint] == '1'){
            endpoint--;
        }

        while(startpoint <= endpoint){

            int one = 0, zero = 0;
            while(startpoint <= endpoint && s[startpoint] == '1'){
                one++;
                startpoint++;
            }
            while(startpoint <= endpoint && s[startpoint] == '0'){
                zero++;
                startpoint++;
            }
            stack1.push_back(one);
            stack2.push_back(zero);

        }

        long long add = 0, ans = 0;

        while(!stack1.empty()){
            ans += stack1.back() * (stack2.back() + add);
            add = stack2.back() + add;
            stack1.pop_back();
            stack2.pop_back();
        }

        return ans;


    }
};
