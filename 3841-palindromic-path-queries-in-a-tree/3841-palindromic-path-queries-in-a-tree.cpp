class Solution {
    int LOG;
    vector<vector<int>> up, adj;
    vector<int> tin, tout, depth, bit;
    int timer = 0;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;

        for (int k = 1; k < LOG; k++)
            up[k][u] = up[k - 1][up[k - 1][u]];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int d = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++)
            if (d & (1 << k))
                u = up[k][u];

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

    void update(int i, int val) {
        for (; i < (int)bit.size(); i += i & -i)
            bit[i] ^= val;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void rangeUpdate(int l, int r, int val) {
        update(l, val);
        if (r + 1 < (int)bit.size())
            update(r + 1, val);
    }

    int prefixMask(int u) {
        return query(tin[u]);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        up.assign(LOG, vector<int>(n));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        bit.assign(n + 2, 0);

        dfs(0, 0);

        for (int u = 0; u < n; u++)
            rangeUpdate(tin[u], tout[u], 1 << (s[u] - 'a'));

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int diff = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                if (diff) {
                    rangeUpdate(tin[u], tout[u], diff);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int mask = prefixMask(u) ^ prefixMask(v)
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};