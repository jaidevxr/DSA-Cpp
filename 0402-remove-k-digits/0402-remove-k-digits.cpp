class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char ch : num) {
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        // Remove remaining digits from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0')
            i++;

        string ans = st.substr(i);

        return ans.empty() ? "0" : ans;
    }
};