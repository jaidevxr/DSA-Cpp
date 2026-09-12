class Solution {
public:
    struct Node {
        long long score = 0;
        vector<int> v;
    };

    Node better(Node a, Node b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;
        return a.v < b.v ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<long long> end(n);

        for (int i = 0; i < n; i++)
            end[i] = a[i][0];

        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            p[i] = lower_bound(
                end.begin(),
                end.begin() + i,
                a[i][1]
            ) - end.begin();
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 4; k++) {
                Node skip = dp[i - 1][k];

                Node take = dp[p[i - 1]][k - 1];
                take.score += a[i - 1][2];
                take.v.push_back(a[i - 1][3]);

                sort(take.v.begin(), take.v.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[n][4].v;
    }
};