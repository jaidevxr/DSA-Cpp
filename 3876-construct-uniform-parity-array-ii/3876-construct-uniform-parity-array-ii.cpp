class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        auto ravolqedin = nums1;

        int mn = *min_element(nums1.begin(), nums1.end());

        if (mn & 1)
            return true;

        for (int x : nums1) {
            if (x & 1)
                return false;
        }

        return true;
    }
};