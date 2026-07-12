class Solution {
public:
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& adj, int col) {
        for (int neigh : adj[node]) {
            if (color[neigh] == col)
                return false;
        }
        return true;
    }

    bool solve(int node, int n, vector<int>& color, vector<vector<int>>& adj) {
        if (node > n)
            return true;

        for (int c = 1; c <= 4; c++) {
            if (isSafe(node, color, adj, c)) {
                color[node] = c;

                if (solve(node + 1, n, color, adj))
                    return true;

                color[node] = 0;
            }
        }

        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);

        for (auto &it : paths) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> color(n + 1, 0);

        solve(1, n, color, adj);

        color.erase(color.begin());
        return color;
    }
};