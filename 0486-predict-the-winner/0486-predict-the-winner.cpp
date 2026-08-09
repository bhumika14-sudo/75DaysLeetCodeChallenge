class Solution {
public:
    int solve(int i, int j, vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;

        if(i == j){
            return nums[i];
        }

        int takeL = nums[i] - solve(i+1, j, nums);
        int takeR = nums[j] - solve(i, j-1, nums);
        return max(takeL, takeR); // curr player choose the better option 
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int diff = solve(0, nums.size()-1, nums);
        return (diff >= 0);
    }
};


// class Solution {
// public:
//     bool solve(int left, int right, vector<int>& nums, int p1, int p2, bool turn) {

//         // 1. No elements left -> check final scores
//         if (left > right) {
//             return p1 >= p2;
//         }

//         // P1's turn
//         if (turn) {
//             // P1 takes left
//             bool takeLeft = solve(left + 1, right, nums, p1 + nums[left], p2, false);
//             // P1 takes right
//             bool takeRight = solve(left, right - 1, nums, p1 + nums[right], p2, false);
//             // P1 needs only ONE winning choice
//             return takeLeft || takeRight;
//         }

//         // P2's turn
//         else {
//             // P2 takes left
//             bool takeLeft = solve(left + 1, right, nums, p1, p2 + nums[left], true);
//             // P2 takes right
//             bool takeRight = solve(left, right - 1, nums, p1, p2 + nums[right], true);
//             // P2 will choose a move that makes P1 lose
//             return takeLeft && takeRight;
//         }
//     }

//     bool predictTheWinner(vector<int>& nums) {
//         return solve(0, nums.size() - 1, nums, 0, 0, true);
//     }
// };