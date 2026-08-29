class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> ans(n);

        for (int i = 0; i < n; ) {
            int j = i + 1;

            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit)
                j++;

            vector<int> pos(idx.begin() + i, idx.begin() + j);
            sort(pos.begin(), pos.end());

            for (int k = 0; k < pos.size(); k++)
                ans[pos[k]] = nums[idx[i + k]];

            i = j;
        }

        return ans;
    }
};