class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mn = 0, mx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn]) mn = i;
            if (nums[i] > nums[mx]) mx = i;
        }

        int l = min(mn, mx), r = max(mn, mx);

        return min({r + 1, n - l, l + 1 + n - r});
    }
};