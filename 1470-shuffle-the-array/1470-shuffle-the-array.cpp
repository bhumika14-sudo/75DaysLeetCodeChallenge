class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = nums.size();
        // int i=0; 
        // int j = n;
        vector<int> ans;

        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        // while(i<n){
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums[j]);
        //     i++;
        //     j++;
        // }
        return ans;
    }
};