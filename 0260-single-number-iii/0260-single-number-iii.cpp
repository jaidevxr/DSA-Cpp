class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xr = 0;

        for (int num : nums) {
            xr ^= (unsigned int)num;
        }

        unsigned int bit = xr & (-xr);

        int a = 0, b = 0;

        for (int num : nums) {
            if ((unsigned int)num & bit)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};