class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0, maxi = 0;
        unordered_map<char, int> mpp;

        while (r < s.size()) {
            mpp[s[r]]++;

            while (mpp[s[r]] > 2) {
                mpp[s[l]]--;

                if (mpp[s[l]] == 0) {
                    mpp.erase(s[l]);
                }

                l++;
            }

            maxi = max(r - l + 1, maxi);
            r++;
        }

        return maxi;
    }
};