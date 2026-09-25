class Solution {
public:
    bool isUgly(int i) {
        if(i==0) return false;
        while(i%2==0){
            i=i/2;
        }
        while(i%3==0){
            i=i/3;
        }
        while(i%5==0){
            i=i/5;
        }
        return i==1;
    }
};