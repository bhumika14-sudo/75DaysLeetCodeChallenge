class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int x : nums){
            mp[x]++;
        }

        int ans=0;
        int maxi = 0;

        for(auto &it : mp){
            if(it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};