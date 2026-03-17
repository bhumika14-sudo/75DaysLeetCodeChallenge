class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        
        for(int num : nums){
            mp[num]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        
        for(auto &p : mp){
            int freq = p.second;
            int num = p.first;
            bucket[freq].push_back(num);
        }
        
        vector<int> ans;
        
        for(int i = bucket.size()-1; i >= 0 && ans.size() < k; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        
        return ans;
    }
};