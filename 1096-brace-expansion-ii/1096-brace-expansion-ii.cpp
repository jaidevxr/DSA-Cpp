class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> res;

        while (i < s.size() && s[i] != '}') {

            set<string> part;

            if (s[i] == '{') {
                i++; // skip {

                part = parse(s, i);

                i++; // skip }
            }
            else {
                part.insert(string(1, s[i]));
                i++;
            }

            // Concatenate with existing results
            if (res.empty()) {
                res = part;
            }
            else {
                set<string> temp;

                for (auto &a : res) {
                    for (auto &b : part) {
                        temp.insert(a + b);
                    }
                }

                res = temp;
            }

            // Union
            if (i < s.size() && s[i] == ',') {
                i++;

                set<string> next = parse(s, i);

                res.insert(next.begin(), next.end());
            }
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};