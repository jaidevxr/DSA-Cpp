class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size()-1,m=s.size()-1;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans=0;
        while(n>=0 && m>=0){
            if(s[m]>=g[n]){
                ans+=1;
                n--;
                m--;
            }
            else{
                n--;
            }
        }
        return ans;
    }
};