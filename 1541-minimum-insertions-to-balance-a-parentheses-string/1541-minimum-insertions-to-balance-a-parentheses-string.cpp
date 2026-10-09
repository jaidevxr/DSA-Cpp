class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); ) {
            if (s[i] == '(') {
                open++;
                i++;
            }
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i += 2;
                } else {
                    ans++;
                    i++;
                }

                if (open > 0)
                    open--;
                else
                    ans++;
            }
        }

        return ans + open * 2;
    }
};