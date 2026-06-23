class Solution {
public:
    int maxPower(string s) {
        int count=1;
        for(int i=0;i<s.length();i++){
            int tempcount=1;
            char letter=s[i];
            while(s[i+1]==letter){
                tempcount++;
                i++;
            }
            count=max(count,tempcount);
        }
        return count;
    }
};