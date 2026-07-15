class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven=n*(2*2+(n-1)*2)/2;
        int sumodd=n*(2*1+(n-1)*2)/2;
        return gcd(sumeven,sumodd);
    }
};