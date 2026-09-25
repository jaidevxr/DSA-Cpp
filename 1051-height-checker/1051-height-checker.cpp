class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> check=heights;
        int count=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<check.size();i++){
            if(check[i]!=heights[i]) count++;
        }
        return count;
    }
};