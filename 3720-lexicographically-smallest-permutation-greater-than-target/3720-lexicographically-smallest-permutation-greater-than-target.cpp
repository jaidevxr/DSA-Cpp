class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        vector<int> c(26);
        for(char x:s)c[x-'a']++;

        string p;
        int i=0,n=s.size();
        while(i<n&&c[t[i]-'a'])p+=t[i],c[t[i++]-'a']--;

        for(int j=i;j>=0;j--){
            if(j<i)c[t[j]-'a']++,p.pop_back();
            if(j==n)continue;

            for(int x=t[j]-'a'+1;x<26;x++)if(c[x]){
                string a=p+char('a'+x);
                c[x]--;
                for(int k=0;k<26;k++)a+=string(c[k],'a'+k);
                return a;
            }
        }
        return "";
    }
};