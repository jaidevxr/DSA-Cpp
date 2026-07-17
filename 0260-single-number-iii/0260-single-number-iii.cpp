class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;

        for (int num : nums) {
            xr ^= num;
        }

        unsigned int bit = (unsigned int)xr & (-(unsigned int)xr);

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