//Question: https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01
//level: Easy

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        unordered_set<int> sett;
        int zerc = 0;

        for(auto num : arr){
            sett.insert(num);
            if(num == 0) zerc++;
        }

        for(auto num : sett){
            if(sett.find(num * 2) != sett.end()){
                if(num == 0 && zerc <= 1) return false;
                return true;
            }
        }
        return false;

    }
};
