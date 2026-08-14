class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0, rightsum = 0;
        int n = cardPoints.size();

        for (int i = 0; i < k; i++) {
            leftsum += cardPoints[i];
        }

        int maxsum = leftsum;
        int rightind = n - 1;

        for (int i = k - 1; i >= 0; i--) {
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rightind--];

            maxsum = max(maxsum, leftsum + rightsum);
        }

        return maxsum;
    }
};