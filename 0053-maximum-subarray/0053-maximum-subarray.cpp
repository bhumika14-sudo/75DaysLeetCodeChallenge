class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            currSum = max(nums[i] , currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

// print this subarray 
// int start = 0;
// int end = 0;
// int currIdx = i;
// int currSum=0;
// int maxSum = INT_MIN;

// for(int i=0; i<n; i++){
//     if(nums[i] > nums[i]+currSum){
//         currIdx = i;
//         currSum = nums[i];
//     }
//     else{
//         currSum += nums[i];
//     }

//     if(currSum > maxSum){
//         maxSum = currSum;
//         start = curridx; 
//         end = i;
//     }
// }