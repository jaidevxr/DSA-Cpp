class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int x = st.top();
                st.pop();

                int val = (x == 0) ? 1 : 2 * x;

                st.top() += val;
            }
        }

        return st.top();
    }
};