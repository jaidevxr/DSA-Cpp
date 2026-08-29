class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), m = n / 2, mid = -1;
        vector<int> cnt(26);

        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                if (mid != -1) return "";
                mid = i;
            }
            cnt[i] /= 2;
        }

        string t = target.substr(0, m);

        auto build = [&](string h) {
            string r = h;
            if (mid != -1) r += char('a' + mid);
            reverse(h.begin(), h.end());
            return r + h;
        };

        vector<int> c = cnt;
        string h;
        bool exact = true;

        for (char x : t) {
            int k = x - 'a';
            if (!c[k]) {
                exact = false;
                break;
            }
            h += x;
            c[k]--;
        }

        if (exact) {
            string p = build(h);
            if (p > target) return p;
        }

        for (int i = m - 1; i >= 0; i--) {
            c = cnt;
            string pre;

            bool ok = true;
            for (int j = 0; j < i; j++) {
                int k = t[j] - 'a';
                if (!c[k]) {
                    ok = false;
                    break;
                }
                pre += t[j];
                c[k]--;
            }

            if (!ok) continue;

            for (int k = t[i] - 'a' + 1; k < 26; k++) {
                if (!c[k]) continue;

                string nh = pre + char('a' + k);
                c[k]--;

                for (int x = 0; x < 26; x++)
                    nh += string(c[x], char('a' + x));

                return build(nh);
            }
        }

        return "";
    }
};