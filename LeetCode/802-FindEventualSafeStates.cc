//Question: https://leetcode.com/problems/find-eventual-safe-states/description/?envType=daily-question&envId=2025-01-24
//Level: Medium

class Solution {
public:
    vector<int> dfs(vector<vector<int>> graph) {
        int m = graph.size();
        vector<vector<int>> parent(m);
        vector<int> outgo(m, 0);

        for (int i = 0; i < m; i++) {
            for (int j : graph[i]) {
                parent[j].push_back(i);
                outgo[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            if (outgo[i] == 0) q.push(i);
        }


        while (!q.empty()) {
            int val = q.front();
            q.pop();
            ans.push_back(val);

            for (int nei : parent[val]) {
                outgo[nei]--;
                if (outgo[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // Sort the safe nodes
        sort(ans.begin(), ans.end());
        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return dfs(graph);
    }
};
