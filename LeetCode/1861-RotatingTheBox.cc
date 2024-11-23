//Question: https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2024-11-23
//Level: Medium

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        for(int i = 0; i < box.size(); i++){

            int a = 0, b = 0;

            while(b < box[i].size() || a < box[i].size()){

                if(box[i][a] == '.'){
                    a++;
                    b = a;
                }
                else if(box[i][a] == '#'){

                    if(b < box[i].size()){

                        if(box[i][b] == '#') b++;
                        else if(box[i][b] == '.') {
                            box[i][b] = '#';
                            box[i][a] = '.';
                            a++;
                        }
                        else{
                            a = b;
                        }
                    }
                    else break;
                }
                else{
                    a++;
                    b = a;
                }

            }


        }

        vector<vector<char>> ans;

        for(int i = 0; i < box[0].size(); i++){
            vector<char> temp;
            for(int j = box.size() - 1; j >= 0; j--){
                temp.push_back(box[j][i]);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};
