class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);

        int n = s.length();
        int left = 0, r = 0, maxsum = 0;

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= left) {
                    left = hash[s[r]] + 1;
                }
            }

            int length = r - left + 1;
            maxsum = max(maxsum, length);

            hash[s[r]] = r;
            r++;
        }

        return maxsum;
    }
};