class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> mpp;
        for (int x : nums) {
            mpp.insert(x);
        }

        for (int i = 1; i <= n + 1; i++) {
            if (mpp.find(i * k) == mpp.end()) {
                return i * k;
            }
        }

        return -1;
    }
};