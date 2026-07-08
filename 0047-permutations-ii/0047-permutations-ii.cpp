class Solution {
public:
    void findper(vector<int>& nums, vector<int>& ds,
                 vector<vector<int>>& ans, vector<bool>& vis) {

        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(vis[i]) continue;

            // Skip duplicates
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1])
                continue;

            vis[i] = true;
            ds.push_back(nums[i]);

            findper(nums, ds, ans, vis);

            ds.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> vis(nums.size(), false);

        findper(nums, ds, ans, vis);

        return ans;
    }
};