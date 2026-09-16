class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;

        for (char c : s) {
            if (isdigit(c)) {
                int d = c - '0';

                if (d > first) {
                    second = first;
                    first = d;
                }
                else if (d > second && d != first) {
                    second = d;
                }
            }
        }

        return second;
    }
};