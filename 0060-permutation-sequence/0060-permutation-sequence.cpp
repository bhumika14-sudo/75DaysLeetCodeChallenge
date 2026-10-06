class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }

        string ans = "";
        int total = 1;
        for(int i = 1; i <= n; i++){
            total *= i;
        }
        int each = total / n;
        while(!nums.empty()){

            int index = (k - 1) / each;
            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);
            k = k - index * each;

            if(nums.size() > 1){
                each = each/nums.size();
            }
        }
        return ans;
    }
};