class Solution {
public:
    vector<int> windowSum;
    vector<vector<int>> dp;
    int solve(int i, int count, int k) {
        // 3 subarrays selected
        if (count == 3)
            return 0;

        // No more windows left
        if (i >= windowSum.size())
            return INT_MIN;

        if (dp[i][count] != -1)
            return dp[i][count];

        // Take
        int take = INT_MIN;
        int next = solve(i + k, count + 1, k);
        if (next != INT_MIN)
            take = windowSum[i] + next;

        // Not Take
        int notTake = solve(i + 1, count, k);
        return dp[i][count] = max(take, notTake);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //Sliding Window 
        int currSum = 0;

        for (int i = 0; i < k; i++)
            currSum += nums[i];

        windowSum.push_back(currSum);
        for (int i = k; i < nums.size(); i++) {
            currSum += nums[i];
            currSum -= nums[i - k];
            windowSum.push_back(currSum);
        }

        dp.assign(windowSum.size() + 1, vector<int>(4, -1));
        int maxSum = solve(0, 0, k);
        
        vector<int> ans;
        int i = 0;
        int count = 0;

        while (count < 3) {
            int take = INT_MIN;

            int next = solve(i + k, count + 1, k);
            if (next != INT_MIN)
                take = windowSum[i] + next;

            int notTake = solve(i + 1, count, k);
            if(take >= notTake) {
                ans.push_back(i);
                i += k;
                count++;
            } 
            else {
                i++;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int maxSum = INT_MIN;
//     vector<int> ans;
//     vector<int> idx;
//     void solve(vector<int>&nums, int k , int i, int count, int currSum){
//         if(count == 3){
//             if(currSum > maxSum){
//                 maxSum = currSum;
//                 ans = idx;
//             }
//             return; //backtrack
//         }

//         if(i > nums.size()-k) return;

//         //take
//         int windowSum = 0;
//         for(int j=i; j<i+k; j++){
//             windowSum += nums[j];
//         }
//         idx.push_back(i);

//         solve(nums, k, i+k, count+1, windowSum + currSum);
//         idx.pop_back();

//         //not take 
//         solve(nums, k, i + 1, count, currSum);
//     }
//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         solve(nums, k, 0, 0, 0);  
//         return ans;
//     }
// };