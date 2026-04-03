class Solution {
public:
    // SHARADHA DIDI APPROACH - 2;
    int BinarySearch(vector<int> &nums, int target , int st , int end){
        int n = nums.size();

        if(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if (nums[mid]>target){
                return BinarySearch(nums, target, st, mid-1);
            }
            else{
                return BinarySearch(nums, target, mid+1, end);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return BinarySearch(nums , target , 0 , nums.size()-1);

        // THIS IS MY APPROACH-1: 
        // int n = nums.size();
        // int st = 0 , end = n-1;

        // while(st<=e){
        //     int mid = st + (end-st)/2;

        //     if(nums[mid]==target){
        //         return mid;
        //     }
        //     else if (target<=nums[mid]){
        //         end = mid-1;
        //     }
        //     else{
        //         st = mid+1;
        //     }
        // } 
        // return -1;

        // MY APPROACH = 3 
        // int n = nums.size();

        // for(int i =0; i<n ; i++){
        //     if(nums[i] == target){
        //         return i;
        //     }
        // }
        // return -1;      
    }
};