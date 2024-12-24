//Question: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/?envType=daily-question&envId=2024-12-24
//Level: Hard

class Solution {
public:
    int diam(vector<vector<int>>& graph, int node, int parent, int& ans) {

        if (parent != -1 && graph[node].size() == 1) return 1;

        int a1 = 0, a2 = 0;

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;

            int depth = diam(graph, neighbor, node, ans);

            if (depth > a1) {
                a2 = a1;
                a1 = depth;
            }
            else if (depth > a2) {
                a2 = depth;
            }
        }

        ans = max(ans, a1 + a2);
        return a1 + 1;

    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int m = 0, n = 0;
        for (auto num : edges1) m = max(m, max(num[0], num[1]));
        for (auto num : edges2) n = max(n, max(num[0], num[1]));

        vector<vector<int>> graph1(m + 1), graph2(n + 1);
        for (auto num : edges1) {
            graph1[num[0]].push_back(num[1]);
            graph1[num[1]].push_back(num[0]);
        }
        for (auto num : edges2) {
            graph2[num[0]].push_back(num[1]);
            graph2[num[1]].push_back(num[0]);
        }

        int d1 = 0, d2 = 0;
        diam(graph1, 0, -1, d1);
        diam(graph2, 0, -1, d2);

        return max(d1, max(d2, ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1));

    }
};
