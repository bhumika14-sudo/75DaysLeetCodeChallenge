class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        int temp = n-k;

        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() > nums[i] && temp>0){
                st.pop();
                temp--;
            }
            st.push(nums[i]);
        }

        //extra element in stack 
        while(st.size() > k){
            st.pop();
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};