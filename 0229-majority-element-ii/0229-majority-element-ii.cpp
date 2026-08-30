class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int f = n/3;
        vector<int>ans;

        unordered_map<int,int> mp;

        for(int x : nums){
            mp[x]++;
        }

        for(int i=0; i<n; i++){
            if(mp[nums[i]] > f){
                if(find(ans.begin(), ans.end(), nums[i]) == ans.end()){
                    ans.push_back(nums[i]);
                }
            }
        }    
        return ans;
    }
};