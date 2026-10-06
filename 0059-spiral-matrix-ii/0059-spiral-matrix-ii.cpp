class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int left = 0, bot = n-1, right = n-1, top = 0;
        int num = 1;

        while(left <= right && top <= bot){
            //left -> right
            for(int i=left; i<=right; i++){
                ans[top][i] = num++;
            }
            top++;

            //top -> bot
            for(int i=top; i<=bot; i++){
                ans[i][right] = num++;
            }
            right--;
            
            // right -> left
            for(int i=right; i>=left; i--){
                ans[bot][i] = num++;
            }
            bot--;

            //bot -> top
            for(int i=bot; i>=top; i--){
                ans[i][left] = num++;
            }
            left++;
        }
        return ans;
    }
};