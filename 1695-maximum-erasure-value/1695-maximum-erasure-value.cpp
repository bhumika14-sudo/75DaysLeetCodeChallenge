class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = 0;

        while(right < n){
            while(st.count(nums[right])){
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            st.insert(nums[right]);
            sum += nums[right];
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};