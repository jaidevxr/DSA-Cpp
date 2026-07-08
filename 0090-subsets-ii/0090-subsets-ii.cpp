class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& ds,
               set<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.insert(ds);
            return;
        }

        // Pick
        ds.push_back(nums[index]);
        solve(index + 1, nums, ds, ans);

        // Not Pick
        ds.pop_back();
        solve(index + 1, nums, ds, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> ds;
        solve(0, nums, ds, ans);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};