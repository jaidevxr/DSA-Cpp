class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
};