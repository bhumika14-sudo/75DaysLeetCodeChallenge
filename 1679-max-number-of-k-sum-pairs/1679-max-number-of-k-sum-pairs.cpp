class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        unordered_map<int, int> mp;

        for(int x : nums) {
            int curr = k - x;

            if(mp[curr] > 0) {
                mp[curr]--;
                count++;
            }
            else {
                mp[x]++;
            }
        }

        return count;
    }
};