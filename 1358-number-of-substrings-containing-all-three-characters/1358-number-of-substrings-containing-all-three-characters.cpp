class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, count = 0;
        unordered_map<char, int> mpp;

        while (r < s.length()) {
            mpp[s[r]]++;

            while (mpp.size() == 3) {
                count += s.length() - r;

                mpp[s[l]]--;

                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);

                l++;
            }

            r++;
        }

        return count;
    }
};