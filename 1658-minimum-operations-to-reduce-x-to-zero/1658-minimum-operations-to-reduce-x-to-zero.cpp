class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if(target < 0)
            return -1;

        int left = 0, sum = 0, longest = -1;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target)
                longest = max(longest, right - left + 1);
        }

        if(longest == -1)
            return -1;

        return nums.size() - longest;
    }
};