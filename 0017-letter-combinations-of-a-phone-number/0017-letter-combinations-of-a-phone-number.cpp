class Solution {
public:
    vector<string> ans;

    vector<string> keypad = {
        "", "",
        "abc", "def",
        "ghi", "jkl",
        "mno", "pqrs",
        "tuv", "wxyz"
    };

    void solve(string &digits, int index, string current) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = keypad[digits[index] - '0'];

        for (char ch : letters) {
            solve(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        solve(digits, 0, "");

        return ans;
    }
};