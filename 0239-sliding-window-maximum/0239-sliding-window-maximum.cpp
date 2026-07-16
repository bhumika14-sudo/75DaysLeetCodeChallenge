class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i=0; i<n; i++){
            //if index is present in the dequeue and we are out of the window , pop that index from dequeue
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //curr number > dq[nums[i]] to pop from dq
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            //store ans if window is complete
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};