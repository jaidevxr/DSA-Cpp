
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        long long sum = 0;
        int k = k1 + k2;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            sum += d;
        }

        if (sum <= k) return 0;

        int low = 0, high = *max_element(diff.begin(), diff.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k) high = mid;
            else low = mid + 1;
        }

        long long ans = 0;

        for (int d : diff) {
            int reduced = min(d, low);
            ans += 1LL * reduced * reduced;
        }

        int remaining = k;

        for (int d : diff) {
            if (d > low) remaining -= d - low;
        }

        for (int i = 0; i < diff.size() && remaining > 0; i++) {
            if (diff[i] >= low && diff[i] > 0) {
                ans -= 2LL * low - 1;
                remaining--;
            }
        }

        return ans;
    }
};
