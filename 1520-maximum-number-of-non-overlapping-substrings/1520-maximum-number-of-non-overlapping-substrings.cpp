class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);

        for(int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if(first[x] == -1) first[x] = i;
            last[x] = i;
        }

        vector<pair<int,int>> v;

        for(int c = 0; c < 26; c++) {
            if(first[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            bool ok = true;

            for(int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                if(first[x] < l) {
                    ok = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if(ok) v.push_back({l, r});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for(auto [l, r] : v) {
            if(l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};