class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxfreq = 0, ans = 0;

        unordered_map<char, int> mpp;

        while (r < s.size()) {

            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);

            while ((r - l + 1) - maxfreq > k) {
                mpp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};