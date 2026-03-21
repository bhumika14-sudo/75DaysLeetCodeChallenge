class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int m = nums.size();
        int curr = 0; 

        for(int i=0 ; i<m ; i++){
            if(nums[i] != 0){
                nums[curr] = nums[i];
                curr++;
            }
        } 

        while( curr < m){
            nums[curr] = 0;
            curr++;
        }
        
    }
};