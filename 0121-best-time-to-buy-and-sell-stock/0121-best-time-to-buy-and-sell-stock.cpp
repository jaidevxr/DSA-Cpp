class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min=prices[0];
        int maxi=INT_MIN;
        for(int i=1;i<n;i++){
            int dif=prices[i]-min;
            maxi=max(dif,maxi);
            if(prices[i]<min){
                min=prices[i];
            }
        }
        if(maxi<=0) return 0;
        else{
            return maxi;
        }
    }
};