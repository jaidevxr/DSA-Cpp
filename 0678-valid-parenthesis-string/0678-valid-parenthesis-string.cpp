class Solution {
public:

    bool ans(string s, int ind, int count, int n,
             vector<vector<int>>& dp) {

        if (count < 0)
            return false;

        if (ind == n)
            return count == 0;

        if (dp[ind][count] != -1)
            return dp[ind][count];

        if (s[ind] == '(')
            return dp[ind][count] =
                ans(s, ind + 1, count + 1, n, dp);

        if (s[ind] == ')')
            return dp[ind][count] =
                ans(s, ind + 1, count - 1, n, dp);

        if (s[ind] == '*') {
            return dp[ind][count] =
                ans(s, ind + 1, count + 1, n, dp) ||
                ans(s, ind + 1, count - 1, n, dp) ||
                ans(s, ind + 1, count, n, dp);
        }

        return false;
    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return ans(s, 0, 0, n, dp);
    }
};