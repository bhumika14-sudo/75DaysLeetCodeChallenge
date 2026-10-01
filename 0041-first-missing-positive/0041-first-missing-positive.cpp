class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int x : nums){
            if(x > 0){
                st.insert(x);
            }
        }

        int ans = 1;

        while(st.count(ans)){
            ans++;
        }
        return ans;
    }
};