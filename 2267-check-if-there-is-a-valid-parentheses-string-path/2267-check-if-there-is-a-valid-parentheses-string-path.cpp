class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {
        // Balance can never be negative
        if (balance < 0)
            return false;

        // Out of bounds
        if (i >= m || j >= n)
            return false;

        // Add current character
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        // Reached destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Already calculated
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move right or down
        return dp[i][j][balance] =
            solve(grid, i + 1, j, balance) ||
            solve(grid, i, j + 1, balance);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n, -1)
        ));

        return solve(grid, 0, 0, 0);
    }
};