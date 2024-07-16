//Question: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16
//Level: 

class Solution {
public:

    bool findPath(TreeNode* root, int value, string &path, string direction){
        
        if (root == nullptr) {
            return false;
        }

        path += direction;

        if (root->val == value) {
            return true;
        }


        if(findPath(root->left, value, path, "L") || findPath(root->right, value, path, "R")){
            return true;
        }


        path.pop_back();
        return false;

    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        string pathToStart;
        string pathToDest;


        findPath(root, startValue, pathToStart, "");
        findPath(root, destValue, pathToDest, "");


        int i = 0;
        while(i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]){
            i++;
        }


        string result;

        for (int j = i; j < pathToStart.size(); j++) {
            result += 'U';
        }

        for (int j = i; j < pathToDest.size(); j++) {
            result += pathToDest[j];
        }


        return result;


    }
};
