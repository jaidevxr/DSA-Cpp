class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        int index = 0;

        for (int i = 0; i < pattern.length(); i++) {

            if (index >= s.length())
                return false;

            string word = "";

            while (index < s.length() && s[index] != ' ') {
                word += s[index];
                index++;
            }

            if (index < s.length())
                index++;

            if (mp1.count(pattern[i])) {
                if (mp1[pattern[i]] != word)
                    return false;
            }
            else {
                mp1[pattern[i]] = word;
            }

            if (mp2.count(word)) {
                if (mp2[word] != pattern[i])
                    return false;
            }
            else {
                mp2[word] = pattern[i];
            }
        }

        
        if (index < s.length())
            return false;

        return true;
    }
};