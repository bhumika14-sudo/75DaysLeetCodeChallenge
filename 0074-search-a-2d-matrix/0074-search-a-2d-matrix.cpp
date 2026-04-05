class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            if(target >= matrix[i][0] && target <= matrix[i][m-1]);

            int left = 0;
            int right = m-1;

            while(left <= right){
                int mid = (left + right)/2;

                if(target == matrix[i][mid]){
                    return true;
                }
                else if(target <= matrix[i][mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
        }
        return false;    
    }
};