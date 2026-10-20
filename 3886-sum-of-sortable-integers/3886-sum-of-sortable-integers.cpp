#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    bool check(int k, const vector<int>& nums) {
        int n = nums.size();
        int prev_max = INT_MIN;

        for (int i = 0; i < n; i += k) {
            int drop_cnt = 0;
            int sub_min = nums[i];
            int sub_max = nums[i];

            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j + 1] < nums[j]) {
                    drop_cnt++;
                }
                sub_min = min(sub_min, nums[j + 1]);
                sub_max = max(sub_max, nums[j + 1]);
            }

            // 1. Minimum of current block must be >= maximum of previous block
            if (sub_min < prev_max) {
                return false;
            }

            // 2. A block can have at most 1 drop inside
            if (drop_cnt > 1) {
                return false;
            }

            // 3. If there is 1 drop, wrap-around condition must hold
            if (drop_cnt == 1 && nums[i + k - 1] > nums[i]) {
                return false;
            }

            prev_max = sub_max;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Iterate over all divisors of n
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (check(k, nums)) {
                    ans += k;
                }
                if (k * k != n) {
                    if (check(n / k, nums)) {
                        ans += n / k;
                    }
                }
            }
        }

        return ans;
    }
};