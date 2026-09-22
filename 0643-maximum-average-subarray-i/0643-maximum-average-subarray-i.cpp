class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = INT_MIN;
        int sum = 0;
        int left = 0, right=0;
        while(right < n){
            sum += nums[right];
            right++;

            if(right - left == k){
                double curr = (double)sum/k;
                ans = max(ans, curr);

                sum -= nums[left];
                left++;
            }
        }
        return ans;
    }
};