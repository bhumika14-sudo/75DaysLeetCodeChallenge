class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int x : cardPoints) total += x;
        int windowSize = n - k;
        int left = 0;
        int sum = 0;
        int minSum = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += cardPoints[right];
            if (right - left + 1 > windowSize) {
                sum -= cardPoints[left];
                left++;
            }
            if (right - left + 1 == windowSize) {
                minSum = min(minSum, sum);
            }
        }
        if (k == n) return total;
        return total - minSum;
    }
};