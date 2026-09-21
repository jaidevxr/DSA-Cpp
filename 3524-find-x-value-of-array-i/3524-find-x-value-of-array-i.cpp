class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for(int num : nums) {
            vector<long long> next(k);

            int x = num % k;

            next[x] = 1;

            for(int r = 0; r < k; r++) {
                int nr = (r * x) % k;
                next[nr] += dp[r];
            }

            for(int r = 0; r < k; r++)
                ans[r] += next[r];

            dp = next;
        }

        return ans;
    }
};