class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int r = 0; r < s.size(); r++) {
            if (s[r] == '1')
                ones++;

            while (ones > k) {
                if (s[l] == '1')
                    ones--;
                l++;
            }

            if (ones == k) {
                while (s[l] == '0')
                    l++;

                int len = r - l + 1;
                string curr = s.substr(l, len);

                if (len < minLen || 
                   (len == minLen && curr < ans)) {
                    minLen = len;
                    ans = curr;
                }
            }
        }

        return ans;
    }
};