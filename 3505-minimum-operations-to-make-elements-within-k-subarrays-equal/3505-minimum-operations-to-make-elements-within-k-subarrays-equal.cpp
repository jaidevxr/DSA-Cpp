class Solution {
    struct BIT {
        int n;
        vector<long long> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void add(int i, long long val) {
            for (; i <= n; i += i & -i)
                bit[i] += val;
        }

        long long sum(int i) {
            long long res = 0;
            for (; i > 0; i -= i & -i)
                res += bit[i];
            return res;
        }

        int kth(int k) {
            int idx = 0;
            for (int step = 1 << 17; step; step >>= 1) {
                int next = idx + step;
                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }
            return idx + 1;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        BIT cnt(m), sum(m);

        auto getIndex = [&](int v) {
            return lower_bound(vals.begin(), vals.end(), v) - vals.begin() + 1;
        };

        auto add = [&](int v, int delta) {
            int id = getIndex(v);
            cnt.add(id, delta);
            sum.add(id, 1LL * v * delta);
        };

        auto getCost = [&]() -> long long {
            int midId = cnt.kth((x + 1) / 2);
            long long median = vals[midId - 1];

            long long leftCount = cnt.sum(midId - 1);
            long long leftSum = sum.sum(midId - 1);

            long long totalSum = sum.sum(m);
            long long rightCount = x - cnt.sum(midId);
            long long rightSum = totalSum - sum.sum(midId);

            return median * leftCount - leftSum
                 + rightSum - median * rightCount;
        };

        int windows = n - x + 1;
        vector<long long> cost(windows);

        for (int i = 0; i < x; i++)
            add(nums[i], 1);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            add(nums[i - x], -1);
            add(nums[i], 1);
            cost[i - x + 1] = getCost();
        }

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};