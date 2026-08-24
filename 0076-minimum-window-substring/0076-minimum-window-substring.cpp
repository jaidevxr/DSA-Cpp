class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        int hash[256] = {0};

        int l = 0, r = 0;
        int minLen = 1e9;
        int stIndex = -1;
        int cnt = 0;

        // Store frequency of characters in t
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {

            // Include s[r] in the window
            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;

            // When window contains all characters of t
            while (cnt == m) {

                // Update minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    stIndex = l;
                }

                // Remove s[l] from window
                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        // No valid window found
        if (stIndex == -1)
            return "";

        return s.substr(stIndex, minLen);
    }
};