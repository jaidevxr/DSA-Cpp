class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& ds,
               vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Pick
        ds.push_back(nums[index]);
        solve(index + 1, nums, ds, ans);

        // Not Pick
        ds.pop_back();
        solve(index + 1, nums, ds, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, nums, ds, ans);
        return ans;
    }
};