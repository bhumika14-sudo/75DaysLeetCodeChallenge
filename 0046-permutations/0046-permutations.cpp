class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<int>& used){
        int n = nums.size();

        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i]) continue;

            used[i] = 1;
            curr.push_back(nums[i]);
            solve(nums, curr, ans, used);

            curr.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> used(n, 0);
        solve(nums, curr, ans, used);
        return ans;
    }
};