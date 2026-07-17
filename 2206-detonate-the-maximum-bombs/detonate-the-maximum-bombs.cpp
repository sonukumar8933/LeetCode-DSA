class Solution {
public:
    typedef long long LL;

    void dfs(int u, unordered_set<int>& visited,
             unordered_map<int, vector<int>>& adj) {

        visited.insert(u);

        for (int v : adj[u]) {
            if (!visited.count(v))
                dfs(v, visited, adj);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {

            LL x1 = bombs[i][0];
            LL y1 = bombs[i][1];
            LL r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];

                LL dx = x2 - x1;
                LL dy = y2 - y1;

                if (dx * dx + dy * dy <= r1 * r1) {
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            dfs(i, visited, adj);
            result = max(result, (int)visited.size());
        }

        return result;
    }
};