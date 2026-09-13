class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> a, b;

        // Store coordinates of all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    a.push_back({i, j});

                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;
        int ans = 0;

        // Count how many pairs have the same shift
        for (auto [r1, c1] : a) {
            for (auto [r2, c2] : b) {
                int dr = r2 - r1;
                int dc = c2 - c1;

                mp[{dr, dc}]++;
                ans = max(ans, mp[{dr, dc}]);
            }
        }

        return ans;
    }
};