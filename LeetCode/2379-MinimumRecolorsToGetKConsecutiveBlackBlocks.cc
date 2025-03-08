//Question: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08
//Level: Easy

class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int p = k - 1;

        int w = 0;
        for(int i = 0; i < k; i++) if(blocks[i] == 'W') w++;

        int ans = w;
        p++;

        while(p < blocks.size()){

            if(blocks[p - k] == 'W') w--;
            if(blocks[p] == 'W') w++;

            ans = min(ans, w);

            p++;
        }

        return ans;

    }
};
