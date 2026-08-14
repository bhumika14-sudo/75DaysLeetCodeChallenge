class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> mp;
        int left = 0;
        int right = 0;
        int ans = 0;

        while(right < n){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int k = st.size();
        return atMost(nums, k) - atMost(nums, k-1);
    }
};